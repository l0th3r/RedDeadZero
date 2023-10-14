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

bool can_slow = true;
bool request_start = false;
bool request_landing = false;
float top_speed = 0;

void update()
{
	player_t* user = init_player();
	controls_t* controls = init_controls();

	update_controls();
	update_player_data(Restriction::r_medium);

	//print_debug();
	print_controls();

	PED::SET_PED_CAN_RAGDOLL(user->ped_id, false);
	MISC::SET_SUPER_JUMP_THIS_FRAME(user->player);
	effects_on_player();

	// search for shooting peds only if a bullet is near (instead of every frame)
	if (user->is_bullet_near)
		update_shooting_peds(shooting_peds, user->ped_id);

	if (!user->is_in_air && controls->attack_key)
	{
		deflect_bullets(shooting_peds);
		print_to_HUD("DEFLECTING BULLETS");
	}

	// charged jump conditions
	if (user->is_in_air && controls->attack_key)
	{
		if (ENTITY::GET_ENTITY_SPEED(user->ped_id) > top_speed)
			top_speed = ENTITY::GET_ENTITY_SPEED(user->ped_id);

		charged_jump();
		request_landing = true;

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
	/*
	add_disable_input("INPUT_ATTACK");
	add_disable_input("INPUT_SPRINT");
	*/

	shooting_peds = create_peds_t();
	update_player_data(Restriction::r_all);

	while (true)
	{
		// check if the mod can be read
		if (can_update_this_frame())
			update();

		WAIT(0);
	}

	// i'm not sure thats useful :/
	destroy_peds_t(shooting_peds);
	destroy_player_t();
	destroy_controls_t();
}

void ScriptMain()
{
	srand(GetTickCount());
	main();
}

// deflection

//BOOL MISC::IS_BULLET_IN_AREA(float p0, float p1, float p2, float p3, BOOL p4)
/*
char buffer[100];
sprintf(buffer, "last impact coord = x: %f / y: %f / z: %f", tmp.x, tmp.y, tmp.z);
print_to_HUD(buffer);
if (user->is_aiming)
{
	MISC::SET_TIME_SCALE(1);
}
*/