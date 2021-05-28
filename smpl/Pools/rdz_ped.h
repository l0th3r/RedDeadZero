#ifndef _RDZ_PED_
#define _RDZ_PED_

// define ped array storage size
const int ARR_SIZE = 1024;

// struct to store peds
struct peds_t
{
	Ped peds[ARR_SIZE];
	int count;
};

// allocate struct pointer
peds_t* create_peds_t();

// return the hash of the weapon held by a ped
Hash get_ped_weapon(Ped playerPed);

// store in _target array peds that are in fight with _player
// return false if nothing was find
void update_shooting_peds(peds_t* _target_t, player_t* _player);

// deallocate peds_t struct
void destroy_peds_t(peds_t* _input);

#endif