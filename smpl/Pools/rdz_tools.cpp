/*
* SOME TOOLS
*/

#include "script.h"
#include "rdz_tools.h"
#include "rdz_player.h"

bool is_bullet_near_player(float distance)
{

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

bool can_update_this_frame(player_t* _input)
{
	bool output = true;

	// check if player ped exists and control is on (exemple not in a cutscene)
	if (!ENTITY::DOES_ENTITY_EXIST(_input->ped_id) || !PLAYER::IS_PLAYER_CONTROL_ON(_input->player))
		output = false;
}