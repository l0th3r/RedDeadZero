/*
* SOME TOOLS
*/

#include "script.h"
#include "rdz_tools.h"

/// func that return a Hash pointer, the weapon currently held by the player.
Hash get_player_weapon()
{
	auto weapon = new Hash;
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	WEAPON::GET_CURRENT_PED_WEAPON(playerPed, weapon, 0, 0, 1);
	return *weapon;
}

// print string to HUD
void print_to_HUD(char* input)
{
	float x = 0.15;
	float y = 0.30;

	HUD::SET_TEXT_SCALE(1, 0.3);
	HUD::_SET_TEXT_COLOR(255, 255, 255, 255);
	const char* result = MISC::_CREATE_VAR_STRING(10, "LITERAL_STRING", input);
	HUD::_DISPLAY_TEXT(result, x, y);
}