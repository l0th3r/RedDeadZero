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

// load all human peds on target struct
void update_human_ped_data(peds_t* target_t);

// deallocate peds_t struct
void destroy_peds_t(peds_t* _input);

#endif