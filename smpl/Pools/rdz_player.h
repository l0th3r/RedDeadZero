#ifndef _RDZ_PLAYER_
#define _RDZ_PLAYER_

// struct to store player data
struct player_t
{
// DATA
	// player entity id
	Player player;
	// player ped id
	Ped ped_id;
	// store the current players weapon
	Hash weapon;
	// store player's postion
	Vector3 pos;
	// store player's rotation
	Vector3 rot;
	// store camera rotation
	Vector3 cam_rot;
	// store forward vector
	Vector3 fwd;
	// store velocity
	Vector3 vel;
	// is true if the player is aiming
	bool is_aiming;
	// is player jumping
	bool is_jumping;
	// is player in air
	bool is_in_air;
	// is defending
	bool is_defending;

// TRIGGERS
	// true if bullet is near player
	bool is_bullet_near;

// RULES
	bool can_deflect;
	bool can_dash;
};

// player update restriction level
enum class Restriction
{
	r_small = 0, // light restriction, update everything.
	r_medium = 1, // medium restriction, update mod things (exemple: trigger zones, etc).
	r_all = 2, // hard restriction, update what is needed every frames.
};

// allocate a player_t struct
player_t* create_player_t();

// get player struct pointer
player_t* init_player();

// update player_t datas
// _restriction (all update previous ones, 1 update 0 and 1):
void update_player_data(Restriction _restriction);

// return true if the player is aiming with specified weapon
bool is_player_aiming_with_weapon(Hash _weapon);

// check if the given coords are in the player
bool is_impact_on_player(Vector3 coords, int _tolerance);

// return true if mod can be executed
bool can_update_this_frame();

// deallocate a player_t struct
void destroy_player_t();

#endif