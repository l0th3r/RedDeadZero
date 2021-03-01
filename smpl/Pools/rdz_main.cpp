#include "script.h"

#include <stdio.h>

#include "rdz_player.h"
#include "rdz_ped.h"
#include "rdz_tools.h"

//ENUM WEAPON HASH - USE SED/tr/cut with pipes |

// store humans that are shooting to player
peds_t* shooting_peds;

// define player data
player_t* user;

bool can_slow = true;

void update()
{
	update_player_data(user, 1);
	print_debug(user);
	
	// is bullet near player
	//BOOL MISC::IS_BULLET_IN_AREA(float p0, float p1, float p2, float p3, BOOL p4)

	if (user->is_bullet_near)
	{
		update_shooting_peds(shooting_peds, user);

		if (user->is_aiming)
		{
			PLAYER::SET_PLAYER_INVINCIBLE(user->player, true);

			Vector3 ped_pos;
			for (int i = 0; i < shooting_peds->count; i++)
			{
				ped_pos = ENTITY::GET_ENTITY_COORDS(shooting_peds->peds[i], true, true);
				GRAPHICS::SET_PARTICLE_FX_BULLET_IMPACT_SCALE(10);
				MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(user->pos.x, user->pos.y, user->pos.z, ped_pos.x, ped_pos.y, ped_pos.z, 99999, true, 0x8580C63E, user->ped_id, false, false, 999, true);
				GRAPHICS::SET_PARTICLE_FX_BULLET_IMPACT_SCALE(1);
			}
		}
		MISC::SET_TIME_SCALE(0.1);
	}

	if(user->is_aiming)
	{
		MISC::SET_TIME_SCALE(1);
	}

	/*char buffer[100];
	sprintf(buffer, "impact position = x: %f / y: %f / z: %f", tmp.x, tmp.y, tmp.z);
	print_to_HUD(buffer);*/
}

void main()
{
	shooting_peds = create_peds_t();
	user = create_player_t();

	update_player_data(user, 2);

	while (true)
	{
		// check if the mod can be read
		if (can_update_this_frame(user))
			update();

		WAIT(0);
	}

	// i'm not sure thats useful :/
	destroy_peds_t(shooting_peds);
	destroy_player_t(user);
}

void ScriptMain()
{	
	srand(GetTickCount());
	main();
}
