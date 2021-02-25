#include "script.h"

/// func that return a Hash pointer, the weapon currently held by the player.
Hash* get_player_weapon()
{
	auto weapon = new Hash;
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	WEAPON::GET_CURRENT_PED_WEAPON(playerPed, weapon, 0, 0, 1);
	return weapon;
}