#include <SFML/Graphics/CircleShape.hpp>
#include <math.h>
#include "Defender.h"

#ifndef PONG_BALL_H
#define PONG_BALL_H

class Ball : public sf::CircleShape {
private:
    const float maxSpeed = 0.5f;
    sf::Vector2f currVelocity;
    bool isActive = false; // if defender made the first move to start the Game
public:
    Ball();

    bool getActive() const;

    void updateBall(Defender &defenderHum, Defender &defenderAi, sf::Vector2f mousePos, bool isStarted);

    void colliderCheck(Defender &defenderHum, Defender &defenderAi);
};

#endif
