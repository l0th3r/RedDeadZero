#pragma once
#ifndef _RDZ_POWERS_
#define _RDZ_POWERS_

#include "rdz_ped.h"

// dash power
void dash();

// super jump power
void charged_jump();

// smash landing power
void smash_landing(float impact_force);

// deflect bullets this frame
void deflect_bullets(peds_t* shooting_peds);

// effects executed every frames
void effects_on_player();

#endif