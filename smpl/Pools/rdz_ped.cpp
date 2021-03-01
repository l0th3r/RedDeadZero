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

void update_shooting_peds(peds_t* _target_t, player_t* _player)
{	
	// to store all peds
	Ped peds[ARR_SIZE];

	// all peds and count
	int count = worldGetAllPeds(peds, ARR_SIZE);

	// reset target counter
	_target_t->count = 0;

	for (int i = 0; i < count; i++)
	{
		if (
			PED::IS_ANY_HOSTILE_PED_NEAR_POINT(_player->ped_id, _player->pos.x, _player->pos.y, _player->pos.z, 60.0) &&
			PED::IS_PED_IN_COMBAT(peds[i], _player->ped_id) &
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

void destroy_peds_t(peds_t* _input)
{
	free(_input);
}