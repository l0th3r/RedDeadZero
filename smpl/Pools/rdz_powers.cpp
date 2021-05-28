/*
* DASH HANDLE
*/

#include "rdz_power.h"
#include "script.h"
#include "rdz_player.h"
#include "rdz_database.h"
#include "rdz_tools.h"

void dash()
{
	player_t* user = init_player();
	Vector3 temp = ENTITY::GET_ENTITY_VELOCITY(user->ped_id, true);

	ENTITY::SET_ENTITY_ROTATION(user->ped_id, user->rot.x, user->rot.y, user->cam_rot.z, 0, true);
	// ENTITY::SET_ENTITY_COORDS_NO_OFFSET(user->ped_id, user->pos.x + (user->fwd.x * 5), user->pos.y + (user->fwd.y * 5), user->pos.z + (user->fwd.z * 5), true, true, true);
	ENTITY::SET_ENTITY_VELOCITY(user->ped_id, temp.x + (user->fwd.x * 10), temp.y + (user->fwd.y * 10), temp.y);
	ENTITY::_0x9587913B9E772D29(user->ped_id, false); // set the player on the ground correctly
}

void charged_jump()
{
	player_t* user = init_player();
	Vector3 temp = ENTITY::GET_ENTITY_VELOCITY(user->ped_id, true);

	TASK::CLEAR_PED_TASKS(user->ped_id, true, true);

	ENTITY::SET_ENTITY_ROTATION(user->ped_id, user->cam_rot.x, user->cam_rot.y, user->cam_rot.z, 0, true);
	ENTITY::SET_ENTITY_VELOCITY(user->ped_id, temp.x + (user->fwd.x * 3), temp.y + (user->fwd.y * 3), -5);
	PLAYER::RESTORE_PLAYER_STAMINA(user->player, 100);
	PLAYER::_0xFECA17CF3343694B(user->player, 100);
}

void smash_landing(float impact_force)
{
	player_t* user = init_player();

	ENTITY::SET_ENTITY_INVINCIBLE(user->ped_id, true);
	//MISC::_FORCE_LIGHTNING_FLASH_AT_COORDS(user->pos.x + (user->fwd.x * 5), user->pos.y + (user->fwd.y * 5), user->pos.z, -0.1f);

	if (impact_force >= 32)
		FIRE::ADD_OWNED_EXPLOSION(user->ped_id, user->pos.x + (user->fwd.x), user->pos.y + (user->fwd.y), user->pos.z - 0.5f , EXP_TAG_DYNAMITE_VOLATILE, 8, true, false, 4);
	else if (impact_force >= 12)
		FIRE::ADD_OWNED_EXPLOSION(user->ped_id, user->pos.x + (user->fwd.x), user->pos.y + (user->fwd.y), user->pos.z - 0.5f, EXP_TAG_RIVER_BLAST, 4, true, false, 2);
	else
		FIRE::ADD_OWNED_EXPLOSION(user->ped_id, user->pos.x + (user->fwd.x), user->pos.y + (user->fwd.y), user->pos.z - 0.5f, EXP_TAG_GRENADE, 1, true, false, 1);
}

void effects_on_player()
{
	player_t* user = init_player();

	//FIRE::ADD_OWNED_EXPLOSION(user->ped_id, user->pos.x, user->pos.y, user->pos.z, EXP_TAG_DIR_STEAM, 0, false, false, 0);
	if (!FIRE::IS_ENTITY_ON_FIRE(user->ped_id))
	{
		FIRE::START_ENTITY_FIRE(user->ped_id, true, false, false);
	}
}