#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Character.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML", sf::Style::Close);
    window.setFramerateLimit(60);

    float frame = 0.0f;
    bool idle;

    Character* player_1 = new Character(character_type::Knight, sf::Vector2f{ 100, 100 });


    while (window.isOpen())
    {
        frame += 0.1f;

        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
        }

        idle = true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) { player_1->move(movement::UP, frame); idle = false; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) { player_1->move(movement::LEFT, frame); idle = false;  }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) { player_1->move(movement::DOWN, frame); idle = false; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) { player_1->move(movement::RIGHT, frame); idle = false; }
        if (idle) player_1->move(movement::IDLE, frame);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) { player_1->change_character(character_type::Knight); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) { player_1->change_character(character_type::Rogue); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) { player_1->change_character(character_type::Mage); }


        window.clear();
        window.draw(player_1->getShape());
        window.display();
    }

    return 0;
}