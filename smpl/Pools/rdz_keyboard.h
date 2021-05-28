#ifndef _RDZ_KEYBOARD_
#define _RDZ_KEYBOARD_

#include "script.h"

struct controls_t
{
	bool dash_key;
	bool attack_key;
	bool sprint_key;
};

// get controls struct pointer
controls_t* init_controls();

// add new disabled input
// bool add_disable_input(string new_input);

// needed to be called every frames
void update_controls();

// Check if key is pressed this frame (need to pass if the input is disabled previously)
bool isInputPressed(string input_hash_name, bool is_disabled);
// Check if key is down this frame (need to pass if the input is disabled previously)
bool isInputDown(string input_hash_name, bool is_disabled);
// check if key is realeased this frame (need to pass if the input is disabled previously)
bool isInputReleased(string input_hash_name, bool is_disabled);

// return key hash with a input name
Hash str_to_hash(string str);

void destroy_controls_t();

#endif