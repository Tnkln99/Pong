#include "../includes/Defender.h"

Defender::Defender(int No) : sf::RectangleShape(sf::Vector2f(160, 20)) {
    this->setFillColor(sf::Color::Magenta);

    if(No == 1)
        this->setPosition(440,10);
    else if(No == 2)
        this->setPosition(440,970);
    else{
        std::cout << "Defender::Defender(int No) : No is not 1 or 2" << std::endl;
        exit(1);
    }
    this->direction = Direction::NONE;
}

Direction Defender::getDirection() {
    return this->direction;
}

void Defender::updateDefender(Direction direction) {
    this->direction = direction;
    if(direction == Direction::LEFT)
        this->move(-1,0);
    else if(direction == Direction::RIGHT)
        this->move(1,0);

}



