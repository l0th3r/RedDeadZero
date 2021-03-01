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
	// is true if the player is aiming
	bool is_aiming;

	//TRIGGERS
	// true if bullet is near player
	bool is_bullet_near;

};

// allocate a player_t struct
player_t* create_player_t();

// update player_t datas
// _restriction (all update previous ones, 1 update 0 and 1):
// 2 hard restriction, update needed every frames.
// 1 medium restriction, update mod things (exemple, trigger zones, etc).
// 0 light restriction, update everything.
void update_player_data(player_t* _player, byte _restriction);

// return true if the player is aiming with specified weapon
bool is_player_aiming_with_weapon(player_t* _player, Hash _weapon);

// return true if mod can be executed
bool can_update_this_frame(player_t* _input);

// deallocate a player_t struct
void destroy_player_t(player_t* _input);

#endif