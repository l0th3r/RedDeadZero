/*
* PLAYER HANDLE
*/

#include "script.h"
#include "rdz_player.h"

#include <stdlib.h>

player_t* create_player_t()
{
	player_t* output;
	output = (player_t*)malloc(sizeof(player_t));

	if (!output)
		output = NULL;

	return output;
}

Hash get_player_weapon(Ped playerPed)
{
	auto weapon = new Hash;
	WEAPON::GET_CURRENT_PED_WEAPON(playerPed, weapon, 0, 0, 1);
	return *weapon;
}

void update_player_data(player_t* _player, byte _restriction)
{
	if (_restriction >= 0)
	{
		_player->pos = ENTITY::GET_ENTITY_COORDS(_player->ped_id, true, 0);
		_player->weapon = get_player_weapon(_player->ped_id);;
	}

	if (_restriction >= 1)
	{


	}

	if (_restriction >= 2)
	{
		_player->player = PLAYER::PLAYER_ID();
		_player->ped_id = PLAYER::PLAYER_PED_ID();
	}
}

void destroy_player_t(player_t* _input)
{
	free(_input);
}