#include <iostream>
#include <SFML/Graphics.hpp>
#include "CircleCollision.h"
#include <stdlib.h>

void renderCirc(sf::RenderWindow &window, sf::CircleShape &circ);
void tickInput(sf::Transformable &obj, float tpf );
void tickPhys();

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;
    sf::RenderWindow window(sf::VideoMode(800, 450), "Collider Sim", sf::Style::Default, settings);

    sf::RectangleShape player(sf::Vector2f(10.f, 150.0f));
    player.setPosition(30.0f, window.getSize().y/2 - player.getSize().y/2);

    sf::CircleShape ball(7.5f);
    ball.setFillColor(sf::Color(20, 200, 200));
    ball.setPosition(window.getSize().x/2, window.getSize().y/2);
    float ballDir;

    float ups = 1.0f / (float)60;
    sf::Clock clock;
    float sec;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sec = clock.getElapsedTime().asSeconds();
        if(sec >= ups){
            tickInput(player, sec);
            tickPhys();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
            clock.restart();
        }
        window.clear();
        window.draw(player);
        window.draw(ball);
        window.display();
    }
    return 0;
}

void tickInput(sf::Transformable &obj, float tpf)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        obj.move(0.0f, -0.1f / tpf);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        obj.move(0.0f, 0.1f / tpf);
    }
}

void tickPhys(){

}
