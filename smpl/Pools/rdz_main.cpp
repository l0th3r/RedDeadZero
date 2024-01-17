#include "script.h"

#include <stdio.h>

#include "rdz_player.h"
#include "rdz_ped.h"
#include "rdz_tools.h"
#include "rdz_keyboard.h"
#include "rdz_power.h"
#include "rdz_database.h"

//GRAPHICS::SET_PARTICLE_FX_BULLET_IMPACT_SCALE(10);

// store humans that are shooting to player
peds_t* shooting_peds;

bool request_start = false;
bool request_landing = false;
float top_speed = 0;

bool update_enabled = true;
bool show_controls = true;

void power_update()
{
	player_t* user = init_player();

	if (update_enabled == false)
	{
		PLAYER::SET_PLAYER_INVINCIBLE(user->player, false);
		PED::SET_PED_CAN_RAGDOLL(user->ped_id, true);
		return;
	}

	controls_t* controls = init_controls();

	update_controls();
	update_player_data(Restriction::r_medium);

	MISC::SET_SUPER_JUMP_THIS_FRAME(user->player);
	PLAYER::SET_PLAYER_INVINCIBLE(user->player, true);
	PED::SET_PED_CAN_RAGDOLL(user->ped_id, false);

	PED::_RESTORE_PED_STAMINA(user->ped_id, 100.0f);
	WEAPON::_HIDE_PED_WEAPONS(user->ped_id, 2, true);

	// search for shooting peds only if a bullet is near (instead of every frame)
	if (user->is_bullet_near)
		update_shooting_peds(shooting_peds, user->ped_id);

	if (!user->is_in_air && controls->attack_key)
	{
		deflect_bullets(shooting_peds);
		
		if(show_controls == true)
			print_to_HUD("DEFLECTING BULLETS");
	}

	// charged jump conditions
	if (user->is_in_air && controls->attack_key)
	{
		if (ENTITY::GET_ENTITY_SPEED(user->ped_id) > top_speed)
			top_speed = ENTITY::GET_ENTITY_SPEED(user->ped_id);

		charged_jump();
		request_landing = true;

		if (show_controls == true)
			print_to_HUD("SUPER DASH");
	}

	// landing
	if (request_landing && !user->is_in_air)
	{
		smash_landing(top_speed);
		request_landing = false;
		top_speed = 0;
	}
}

void main()
{
	shooting_peds = create_peds_t();
	update_player_data(Restriction::r_all);

	while (true)
	{
		if (can_update_this_frame())
		{
			if (show_controls == true)
			{
				if(update_enabled == true)
					print_controls();
			}

			if (isInputPressed("INPUT_CREATOR_RT", false) == true)
			{
				update_enabled = !update_enabled;
			}

			if (isInputPressed("INPUT_CREATOR_LT", false) == true)
			{
				show_controls = !show_controls;
			}

			power_update();
		}

		WAIT(0);
	}

	destroy_peds_t(shooting_peds);
	destroy_player_t();
	destroy_controls_t();
}

void ScriptMain()
{
	srand(GetTickCount64());
	main();
}