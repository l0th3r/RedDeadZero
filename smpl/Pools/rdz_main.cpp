#include "script.h"

#include <stdio.h>

#include "rdz_player.h"
#include "rdz_ped.h"
#include "rdz_tools.h"
#include "rdz_keyboard.h"

//GRAPHICS::SET_PARTICLE_FX_BULLET_IMPACT_SCALE(10);

// store humans that are shooting to player
peds_t* shooting_peds;

bool can_slow = true;

void update()
{
	player_t* user = init_player();
	controls_t* controls = init_controls();

	update_controls();
	update_player_data(Restriction::r_medium);
	print_debug();

	MISC::SET_SUPER_JUMP_THIS_FRAME(user->player);

	if (controls->dash_key)
	{
		ENTITY::SET_ENTITY_ROTATION(user->ped_id, user->rot.x, user->rot.y, user->cam_rot.z, 0, true);
		//ENTITY::SET_ENTITY_VELOCITY(user->ped_id, user->fwd.x * 20, user->fwd.y * 20, user->fwd.z * 20);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(user->ped_id, user->pos.x + (user->fwd.x * 5), user->pos.y + (user->fwd.y * 5), user->pos.z + (user->fwd.z * 5), true, true, true);
		ENTITY::_0x9587913B9E772D29(user->ped_id, false); // set the player on the ground correctly
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
