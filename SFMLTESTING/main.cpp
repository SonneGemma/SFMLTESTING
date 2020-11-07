#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Character.h"
#include "Enemy.h"
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML", sf::Style::Close);
    window.setFramerateLimit(60);

    float frame = 0.0f;
    bool idle;
    bool idle_enemies;

    Player* player_1 = new Player(character_type::Knight, sf::Vector2f{ 100, 100 }, 3.0f);
    Enemy* enemy_1 = new Enemy(enemy_type::Cry, sf::Vector2f{ 400, 400 }, 2.0f);

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
        idle_enemies = true;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) { player_1->move(movement::UP, frame); idle = false; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) { player_1->move(movement::LEFT, frame); idle = false;  }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) { player_1->move(movement::DOWN, frame); idle = false; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) { player_1->move(movement::RIGHT, frame); idle = false; }
        if (idle) player_1->move(movement::IDLE, frame);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) { player_1->change_character(character_type::Knight); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) { player_1->change_character(character_type::Rogue); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) { player_1->change_character(character_type::Mage); }

        //testing
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) { player_1->change_idle_type(idle_type::JUMPING); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) { player_1->change_idle_type(idle_type::STANDARD); }

        if (idle_enemies) enemy_1->move(movement::IDLE, frame);

        window.clear();
        window.draw(player_1->getShape());
        window.draw(enemy_1->getShape());
        window.display();
    }

    return 0;
}