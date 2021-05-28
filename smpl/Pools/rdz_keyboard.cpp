#include "rdz_keyboard.h"
#include "script.h"

// input database
// https://github.com/femga/rdr3_discoveries/tree/master/Controls

controls_t* init_controls()
{
	static controls_t* contr = NULL;

	if (!contr)
		contr = (controls_t*)malloc(sizeof(controls_t*));

	return contr;
}

/* 
bool add_disable_input(string new_input)
{
	controls_t* controls = init_controls();
	string* temp = NULL;
	bool response = false;

	temp = (string*)realloc(controls->disable_inputs, controls->d_count + 1);
	
	if (temp)
	{
		controls->disable_inputs[controls->d_count] = new_input;
		controls->d_count++;
		response = true;
	}

	return response;
}
*/

void update_controls()
{
	controls_t* controls = init_controls();

	controls->attack_key = isInputDown("INPUT_ATTACK", true);
	controls->dash_key = isInputPressed("INPUT_SPRINT", true);
	controls->sprint_key = isInputDown("INPUT_SPRINT", true);

	PAD::DISABLE_CONTROL_ACTION(0, str_to_hash("INPUT_ATTACK"), true);
	// PAD::DISABLE_CONTROL_ACTION(0, str_to_hash("INPUT_SPRINT"), true);
}

bool isInputPressed(string input_hash_name, bool is_disabled)
{
	if(is_disabled)
		return PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, str_to_hash(input_hash_name));
	else
		return PAD::IS_CONTROL_JUST_PRESSED(0, str_to_hash(input_hash_name));
}

bool isInputDown(string input_hash_name, bool is_disabled)
{
	if (is_disabled)
		return PAD::IS_DISABLED_CONTROL_PRESSED(0, str_to_hash(input_hash_name));
	else
		return PAD::IS_CONTROL_PRESSED(0, str_to_hash(input_hash_name));
}

bool isInputReleased(string input_hash_name, bool is_disabled)
{
	if (is_disabled)
		return PAD::IS_DISABLED_CONTROL_JUST_RELEASED(0, str_to_hash(input_hash_name));
	else
		return PAD::IS_CONTROL_JUST_RELEASED(0, str_to_hash(input_hash_name));
}

Hash str_to_hash(string str)
{
	return MISC::GET_HASH_KEY(str.c_str());
}

void destroy_controls_t()
{
	controls_t* controls = init_controls();
	free(controls);
}