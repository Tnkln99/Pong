#include <SFML/Graphics.hpp>
#include "../includes/Defender.h"
#include "../includes/Ball.h"


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

    Defender defender1 = Defender(1);
    Defender defender2 = Defender(2);


    Ball ball = Ball();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
        ball.updateBall(defender1, defender2, mousePos, sf::Keyboard::isKeyPressed(sf::Keyboard::Space));

        Direction direction = inputToDirection();
        defender1.updateDefender(direction,ball.getPosition().x, ball.getActive());
        defender2.updateDefender(direction,ball.getPosition().x, ball.getActive());

        window.clear();

        window.draw(defender1);
        window.draw(defender2);

        window.draw(ball);

        window.display();
    }

    return 0;
}