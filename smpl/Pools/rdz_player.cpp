/*
* PLAYER HANDLE
*/

#include "script.h"
#include "rdz_player.h"
#include "rdz_ped.h"

#include <stdlib.h>

player_t* create_player_t()
{
	player_t* output = (player_t*)malloc(sizeof(player_t));

	if (!output)
		output = NULL;

	return output;
}

player_t* init_player()
{
	static player_t* player = NULL;

	if (!player)
	{
		player = create_player_t();

		if(player)
		{
			player->can_deflect = true;
			player->can_dash = true;
		}
	}
	return player;
}

bool check_bullet_impacted_player(Vector3 _pos, int _radius)
{
	return MISC::HAS_BULLET_IMPACTED_IN_AREA(_pos.x - _radius, _pos.y - _radius, _pos.x + _radius, _pos.y + _radius, 0, 1);
}

bool check_bullet_near_player(Vector3 _pos, int _radius)
{
	return MISC::IS_BULLET_IN_AREA(_pos.x - _radius, _pos.y - _radius, _pos.x + _radius, _pos.y + _radius, false);
}

void update_player_data(Restriction _restriction)
{
	player_t* _player = init_player();

	if (_restriction >= Restriction::r_small)
	{
		_player->pos = ENTITY::GET_ENTITY_COORDS(_player->ped_id, true, 0);
		_player->rot = ENTITY::GET_ENTITY_ROTATION(_player->ped_id, 0);
		_player->cam_rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		_player->fwd = ENTITY::GET_ENTITY_FORWARD_VECTOR(_player->ped_id);
		_player->is_jumping = PED::IS_PED_JUMPING(_player->ped_id);
		_player->weapon = get_ped_weapon(_player->ped_id);
	}

	if (_restriction >= Restriction::r_medium)
	{
		_player->is_bullet_near = check_bullet_near_player(_player->pos, 20);
		_player->is_aiming = PLAYER::IS_PLAYER_FREE_AIMING(_player->player);
	}

	if (_restriction >= Restriction::r_all)
	{
		_player->player = PLAYER::PLAYER_ID();
		_player->ped_id = PLAYER::PLAYER_PED_ID();
	}
}

bool is_player_aiming_with_weapon(Hash _weapon)
{
	player_t* _player = init_player();

	if (_player->is_aiming && _player->weapon == _weapon)
		return true;
	else
		return false;
}

bool can_update_this_frame()
{
	player_t* _player = init_player();
	bool output = true;

	// check if player ped exists and control is on (exemple not in a cutscene)
	if (!ENTITY::DOES_ENTITY_EXIST(_player->ped_id) || !PLAYER::IS_PLAYER_CONTROL_ON(_player->player))
		output = false;

	return output;
}

void destroy_player_t()
{
	player_t* user = init_player();

	free(user);
}