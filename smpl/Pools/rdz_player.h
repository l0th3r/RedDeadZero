#ifndef _RDZ_PLAYER_
#define _RDZ_PLAYER_

// struct to store player data
struct player_t
{
	// player entity id
	Player player;
	// player ped id
	Ped ped_id;
	// store the current players weapon
	Hash weapon;
	// store player's postion
	Vector3 pos;
};

// allocate a player_t struct
player_t* create_player_t();

// update player_t datas
// _restriction (all update previous ones, 1 update 0 and 1):
// 2 hard restriction, update needed every frames.
// 1 medium restriction, update mod things (exemple, trigger zones, etc).
// 0 light restriction, update everything.
void update_player_data(player_t* _player, byte _restriction);

// deallocate a player_t struct
void destroy_player_t(player_t* _input);

#endif