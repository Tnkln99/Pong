#include "../includes/Ball.h"

Ball::Ball() : sf::CircleShape(6) {
    this->setFillColor(sf::Color::Cyan);
    this->setPosition(515, 950);
}

bool Ball::getActive() const {
    return this->isActive;
}

void Ball::updateBall(Defender &defender1) {
    if(!isActive){
        setPosition(defender1.getPosition().x + 75, 950);
    }
    else{
        //TODO: implement ball movement
    }
}


