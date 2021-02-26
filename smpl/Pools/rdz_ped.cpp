/*
* PED HANDLE
*/

#include "script.h"
#include "rdz_ped.h"
#include <stdlib.h>


peds_t* create_peds_t()
{
	peds_t* output;
	output = (peds_t*)malloc(sizeof(peds_t));

	if (!output)
		output = NULL;
	else
		output->count = 0;

	return output;
}

void update_human_ped_data(peds_t* target_t)
{
	// to store all peds
	Ped all_peds[ARR_SIZE];
	// all peds count
	int tmp_c = 0;

	// load all peds
	tmp_c = worldGetAllPeds(all_peds, ARR_SIZE);

	// reset human count
	target_t->count = 0;

	// only set export human ones
	for (int i = 0; i < tmp_c; i++)
	{
		if (PED::IS_PED_HUMAN(all_peds[i]))
		{
			target_t->peds[target_t->count] = all_peds[i];
			target_t->count++;
		}
	}
}

void destroy_peds_t(peds_t* _input)
{
	free(_input);
}