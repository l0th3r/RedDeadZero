/*
* PED HANDLE
*/

#include "script.h"
#include "rdz_player.h"
#include "rdz_ped.h"
#include "rdz_tools.h"

#include <stdlib.h>
#include <stdio.h>

peds_t* create_peds_t()
{
	peds_t* output;
	output = (peds_t*)malloc(sizeof(peds_t));

	if (!output)
		output = NULL;
	else
		output->count = 0;

	return output;
}

void update_shooting_peds(peds_t* _target_t, Ped _target)
{
	// to store all peds
	Ped peds[ARR_SIZE];

	// all peds and count
	int count = worldGetAllPeds(peds, ARR_SIZE);

	Vector3 target_pos = ENTITY::GET_ENTITY_COORDS(_target, true, 0);

	// reset target counter
	_target_t->count = 0;

	for (int i = 0; i < count; i++)
	{
		if (
			PED::IS_ANY_HOSTILE_PED_NEAR_POINT(_target, target_pos.x, target_pos.y, target_pos.z, 60.0) &&
			PED::IS_PED_IN_COMBAT(peds[i], _target) &
			!(PED::GET_PED_RELATIONSHIP_GROUP_HASH(peds[i]) == 0x3D714F12) &&
			PED::IS_PED_HUMAN(peds[i]) & !PED::IS_PED_A_PLAYER(peds[i]) &
			!PED::IS_PED_DEAD_OR_DYING(peds[i], true)
		)
		{
			// load it in the target s truct
			_target_t->peds[_target_t->count] = peds[i];
			_target_t->count++;
		}
	}
}

Hash get_ped_weapon(Ped playerPed)
{
	auto weapon = new Hash;
	WEAPON::GET_CURRENT_PED_WEAPON(playerPed, weapon, 0, 0, 1);
	return *weapon;
}

void destroy_peds_t(peds_t* _input)
{
	free(_input);
}