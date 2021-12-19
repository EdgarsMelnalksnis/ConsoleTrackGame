#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include "vehicle.h"

class Player {
    public:
        Player (std::string n, int l, Vehicle v);
        
        int moveVehicle(uint8_t dir, int count);
    private:

        std::string name;
        int lives;
        int score;
        Vehicle v; 

};


#endif
