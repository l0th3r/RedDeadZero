#include "script.h"

#include <stdio.h>

#include "rdz_tools.h"
#include "rdz_ped.h"

//ENUM WEAPON HASH - USE SED/tr/cut with pipes |
//void SET_PARTICLE_FX_BULLET_IMPACT_SCALE(float scale)
//MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(float x1, float y1, float z1, float x2, float y2, float z2, int damage, BOOL p7, Hash weaponHash, Ped ownerPed, BOOL isAudible, BOOL isInvisible, float speed, BOOL p13);
//BOOL IS_BULLET_IN_AREA(float p0, float p1, float p2, float p3, BOOL p4)

// define a human struct (to store only human_peds peds)
peds_t* human_peds;

void update()
{
	// player
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	// check if player ped exists and control is on (e.g. not in a cutscene)
	if (!ENTITY::DOES_ENTITY_EXIST(playerPed) || !PLAYER::IS_PLAYER_CONTROL_ON(player))
		return;
}

void main()
{
	//allocate human_peds struct
	human_peds = create_peds_t();

	// load human_peds before update all frame
	update_human_ped_data(human_peds);

	while (true)
	{
		update();
		WAIT(0);
	}

	destroy_peds_t(human_peds);
}

void ScriptMain()
{	
	srand(GetTickCount());
	main();
}
