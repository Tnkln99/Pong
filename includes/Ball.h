#include <SFML/Graphics/CircleShape.hpp>
#include "../includes/Defender.h"

#ifndef PONG_BALL_H
#define PONG_BALL_H

class Ball : public sf::CircleShape {
private:
    bool isActive = false; // if defender made the first move to start the game
public:
    Ball();

    bool getActive() const;

    void updateBall(Defender &defender1);
};


#endif //PONG_BALL_H
