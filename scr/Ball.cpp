#include "../includes/Ball.h"

Ball::Ball() : sf::CircleShape(6) {
    this->setFillColor(sf::Color::Cyan);
    this->setPosition(515, 950);
}

bool Ball::getActive() const {
    return this->isActive;
}

void Ball::colliderCheck(Defender &defenderHum, DefenderAi &defenderAi) {
    if (this->getGlobalBounds().intersects(defenderHum.getGlobalBounds())) {
        this->currVelocity.y = -this->currVelocity.y;
    }
    else if (this->getGlobalBounds().intersects(defenderAi.getGlobalBounds())) {
        this->currVelocity.y = -this->currVelocity.y;
    }
    else if (this->getPosition().x < 0) {
        this->currVelocity.x = -this->currVelocity.x;
    }
    else if (this->getPosition().x > 1000) {
        this->currVelocity.x = -this->currVelocity.x;
    }
}

void Ball::updateBall(Defender &defenderHum, DefenderAi &defenderAi, sf::Vector2f mousePos, bool isStarted) {
    if(!isActive){
        setPosition(defenderHum.getPosition().x + 75, 950);
        if(isStarted){
            isActive = true;
            sf::Vector2f aimDir;
            sf::Vector2f aimDirNorm;

            aimDir = mousePos - getPosition();
            aimDirNorm = aimDir / sqrt(aimDir.x * aimDir.x + aimDir.y * aimDir.y);

            currVelocity = aimDirNorm * maxSpeed;

            move(currVelocity);
        }
    }
    else{
        colliderCheck(defenderHum, defenderAi);
        move(currVelocity);
    }
}


