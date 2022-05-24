#include "Defender.h"
#include <SFML/Graphics/CircleShape.hpp>


#ifndef PONG_DEFENDERAI_H
#define PONG_DEFENDERAI_H


class DefenderAi : public Defender {
public:
    explicit DefenderAi();

    void updateDefender(sf::CircleShape &ball);
};


#endif
