/*
* SOME TOOLS
*/

#include "script.h"
#include "rdz_player.h"
#include "rdz_tools.h"
#include "rdz_ped.h"
#include "rdz_keyboard.h"

#include <stdio.h>

float get_fps()
{
	return 1 / MISC::GET_FRAME_TIME();
}

void print_to_screen(char* _input, Vector2 _pos)
{
	HUD::SET_TEXT_SCALE(1, 0.3);
	HUD::_SET_TEXT_COLOR(255, 255, 255, 255);
	const char* result = MISC::_CREATE_VAR_STRING(10, "LITERAL_STRING", _input);
	HUD::_DISPLAY_TEXT(result, _pos.x, _pos.y);
}

void print_debug()
{
	player_t* _player = init_player();
	controls_t* controls = init_controls();
	char buffer[100];

	Vector2 pos;
	pos.x = 0.10;
	pos.y = 0.20;

	print_to_screen("=== DEBUG ===", pos);
	pos.y += 0.04;

	sprintf(buffer, "FPS = %f", get_fps());
	print_to_screen(buffer, pos);
	pos.y += 0.03;

	sprintf(buffer, "player position = x: %f / y: %f / z: %f", _player->pos.x, _player->pos.y, _player->pos.z);
	print_to_screen(buffer, pos);
	pos.y += 0.03;

	sprintf(buffer, "player rotation = x: %f / y: %f / z: %f", _player->rot.x, _player->rot.y, _player->rot.z);
	print_to_screen(buffer, pos);
	pos.y += 0.03;

	sprintf(buffer, "camera rotation = x: %f / y: %f / z: %f", _player->cam_rot.x, _player->cam_rot.y, _player->cam_rot.z);
	print_to_screen(buffer, pos);
	pos.y += 0.03;

	sprintf(buffer, "fwd vector = x: %f / y: %f / z: %f", _player->fwd.x, _player->fwd.y, _player->fwd.z);
	print_to_screen(buffer, pos);
	pos.y += 0.03;

	Vector3 vel = ENTITY::GET_ENTITY_VELOCITY(_player->ped_id, true);
	sprintf(buffer, "velocity = x: %f / y: %f / z: %f", vel.x, vel.y, vel.z);
	print_to_screen(buffer, pos);
	pos.y += 0.03;

	sprintf(buffer, "is aiming = %d", _player->is_aiming);
	print_to_screen(buffer, pos);
	pos.y += 0.03;

	sprintf(buffer, "is bullet impacted player = %d", _player->is_bullet_near);
	print_to_screen(buffer, pos);
	pos.y += 0.03;

	sprintf(buffer, "player weapon = %u", _player->weapon);
	print_to_screen(buffer, pos);
	pos.y += 0.03;

	sprintf(buffer, "attack key = %d", controls->attack_key);
	print_to_screen(buffer, pos);
	pos.y += 0.03;

	sprintf(buffer, "dash key = %d", controls->dash_key);
	print_to_screen(buffer, pos);
	pos.y += 0.03;

	sprintf(buffer, "is player jumping = %d", _player->is_jumping);
	print_to_screen(buffer, pos);
	pos.y += 0.03;

	sprintf(buffer, "is player in air = %d", _player->is_in_air);
	print_to_screen(buffer, pos);
	pos.y += 0.03;

	print_to_screen("=============", pos);
}

void print_to_HUD(char* input)
{
	Vector2 pos;
	pos.x = 0.5f;
	pos.y = 0.1f;

	print_to_screen(input, pos);
}