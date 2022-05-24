#include <SFML/Graphics/CircleShape.hpp>
#include "../includes/DefenderAi.h"
#include <math.h>

#ifndef PONG_BALL_H
#define PONG_BALL_H

class Ball : public sf::CircleShape {
private:
    const float maxSpeed = 0.5f;
    sf::Vector2f currVelocity;
    bool isActive = false; // if defender made the first move to start the game
public:
    Ball();

    bool getActive() const;

    void colliderCheck(Defender &defenderHum, DefenderAi &defenderAi);

    void updateBall(Defender &defenderHum, DefenderAi &defenderAi, sf::Vector2f mousePos, bool isStarted);
};


#endif //PONG_BALL_H
