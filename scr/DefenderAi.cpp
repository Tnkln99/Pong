#include "../includes/DefenderAi.h"


DefenderAi::DefenderAi() : Defender() {
    this->setPosition(440,10);
}

void DefenderAi::updateDefender(sf::CircleShape &ball) {
    if (this->getPosition().x < 10 ) {
        setPosition(10, this->getPosition().y);
    }
    else if (this->getPosition().x > 830) {
        setPosition(830, this->getPosition().y);
    }

    if(ball.getPosition().x < this->getPosition().x){
        this->move(-1,0);
    }
    else if(ball.getPosition().x > this->getPosition().x) {
        this->move(1, 0);
    }
}
