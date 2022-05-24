#include "../includes/Defender.h"

Defender::Defender(int type) : sf::RectangleShape(sf::Vector2f(160, 20)) {
    this->setFillColor(sf::Color::Magenta);
    this->type = type;
    if(type == 1 )
        this->setPosition(440,970);
    else if(type == 2)
        this->setPosition(440,10);
    else{
        std::cout << "Error: Defender type not set" << std::endl;
        exit(2);
    }

}

void Defender::updateDefender(Direction direction, float ball_Position_X, bool isGameStarted) {
    if (this->getPosition().x < 10 ) {
        setPosition(10, this->getPosition().y);
    }
    else if (this->getPosition().x > 830) {
        setPosition(830, this->getPosition().y);
    }

    if(type == 1){
        if(direction == Direction::LEFT)
            this->move(-1,0);
        else if(direction == Direction::RIGHT)
            this->move(1,0);
    }
    else {
        if (!isGameStarted) return;
        if(ball_Position_X < this->getPosition().x){
            this->move(-1,0);
        }
        else if(ball_Position_X > this->getPosition().x) {
            this->move(1, 0);
        }
    }


}





