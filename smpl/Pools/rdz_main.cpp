#include "script.h"

#include <stdio.h>

#include "rdz_tools.h"
#include "rdz_ped.h"
#include "rdz_player.h"

//ENUM WEAPON HASH - USE SED/tr/cut with pipes |
//void SET_PARTICLE_FX_BULLET_IMPACT_SCALE(float scale)
//MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(float x1, float y1, float z1, float x2, float y2, float z2, int damage, BOOL p7, Hash weaponHash, Ped ownerPed, BOOL isAudible, BOOL isInvisible, float speed, BOOL p13);
//BOOL IS_BULLET_IN_AREA(float p0, float p1, float p2, float p3, BOOL p4)

// define a human struct (to store only human_peds peds)
peds_t* human_peds;

// define player data
player_t* user;

void update()
{
	bool temp;

	update_player_data(user, 1);
	temp = MISC::IS_BULLET_IN_AREA(user->pos.x - 10, user->pos.y - 10, user->pos.x + 10, user->pos.y + 10, 1);


	char buffer[50];
	sprintf(buffer, "res = %d", temp);
	print_to_HUD(buffer);
}

void main()
{
	human_peds = create_peds_t();
	user = create_player_t();

	update_human_ped_data(human_peds);
	update_player_data(user, 2);

	while (true)
	{
		update();
		WAIT(0);
	}

	// i'm not sure thats useful :/
	destroy_peds_t(human_peds);
	destroy_player_t(user);
}

void ScriptMain()
{	
	srand(GetTickCount());
	main();
}
