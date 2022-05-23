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
private:
    Direction direction;
public:
    explicit Defender(int No);

    Direction getDirection();

    void updateDefender(Direction direction);
};


#endif //PONG_DEFENDER_H
