#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

#ifndef PONG_DEFENDER_H
#define PONG_DEFENDER_H

enum class Direction {
    LEFT,
    RIGHT,
    NONE
};

class Defender : public sf::RectangleShape {
public:
    explicit Defender();

    void updateDefender(Direction direction);
};


#endif //PONG_DEFENDER_H
