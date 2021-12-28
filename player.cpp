#include "player.h"
Player::Player(std::string str, int l,Vehicle Veh) {
    this->name = str;
    this->lives = l;
    this->v = Veh;
}

int Player::moveVehicle(uint8_t dir, int count) {
    int return_val = count; 	
    for (int i = 0; i < count; ++i) {
	switch (dir) { 
	    case KEY_LEFT: 	    
		break;
	    case KEY_RIGHT: 	    
		break;
	    case KEY_UP: 	    
		break;
	    case KEY_DOWN: 	    
		break;
	}
    }
    return return_val;
}
