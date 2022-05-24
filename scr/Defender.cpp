#include "../includes/Defender.h"

Defender::Defender() : sf::RectangleShape(sf::Vector2f(160, 20)) {
    this->setFillColor(sf::Color::Magenta);
    this->setPosition(440,970);
}

void Defender::updateDefender(Direction direction) {
    if (this->getPosition().x < 10 ) {
        setPosition(10, this->getPosition().y);
    }
    else if (this->getPosition().x > 830) {
        setPosition(830, this->getPosition().y);
    }
    else if(direction == Direction::LEFT)
        this->move(-1,0);
    else if(direction == Direction::RIGHT)
        this->move(1,0);

}





