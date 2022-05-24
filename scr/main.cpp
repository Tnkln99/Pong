#include <SFML/Graphics.hpp>
#include "../includes/Defender.h"
#include "../includes/Ball.h"
#include "../includes/DefenderAi.h"

Direction inputToDirection(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        return Direction::LEFT;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        return Direction::RIGHT;
    }
    else{
        return Direction::NONE;
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Game",sf::Style::Close);

    DefenderAi defender1 = DefenderAi();
    Defender defender2 = Defender();

    Ball ball = Ball();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        defender1.updateDefender(ball);

        Direction direction = inputToDirection();
        defender2.updateDefender(direction);

        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
        ball.updateBall(defender2, defender1, mousePos, sf::Keyboard::isKeyPressed(sf::Keyboard::Space));

        window.clear();

        window.draw(defender1);
        window.draw(defender2);

        window.draw(ball);

        window.display();
    }

    return 0;
}