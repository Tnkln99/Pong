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
    int type; // type 1 = human, type 2 = ai
public:
    explicit Defender(int type);

    void updateDefender(Direction direction, float ball_Position_X, bool isGameStarted);
};


#endif //PONG_DEFENDER_H
