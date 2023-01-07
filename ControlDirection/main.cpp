#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return EXIT_FAILURE;
    }
    enum class Direction { LEFT_TO_RIGHT , RIGHT_TO_LEFT };
    enum class Speed { FAST, SLOW };

    Direction direction = Direction::RIGHT_TO_LEFT;
    Speed speed = Speed::FAST;

    sf::String string("Hello");
    sf::Text text(string, font, 200);
    text.setFillColor(sf::Color(0, 255, 0));  // r,g,b,a range[0, 255]

    sf::CircleShape circle(2);
    circle.setFillColor(sf::Color(0, 0, 0));

    sf::RenderWindow w(sf::VideoMode(500, 250), "SFML Window");
    if (direction == Direction::RIGHT_TO_LEFT) {
        text.setPosition((float)w.getSize().x, 0);
    }
    while (w.isOpen()) {
        sf::Event evt;
        if (w.pollEvent(evt)) {
            switch (evt.type) {
            case sf::Event::Closed:
                w.close();
                break;
            case sf::Event::KeyPressed:
                if (evt.key.code == sf::Keyboard::Key::Left) {
                    direction = Direction::RIGHT_TO_LEFT;
                }
                if (evt.key.code == sf::Keyboard::Key::Right) {
                    direction = Direction::LEFT_TO_RIGHT;
                }
                break;
            default:
                break;
            }
        }
        w.clear();
        w.draw(text);
        for (unsigned int i = 0; i < w.getSize().x; i += 4) {
            for (unsigned int j = 0; j < w.getSize().y; j += 4) {
                circle.setPosition((float)i, (float)j);
                w.draw(circle);
            }
        }
        w.display();

        float diff;
        switch (speed) {
        case Speed::FAST:
            diff = 0.1f * 40;
            break;
        case Speed::SLOW:
            diff = 0.01f * 40;
            break;
        }

        switch (direction) {
        case Direction::LEFT_TO_RIGHT:
            if (text.getPosition().x > w.getSize().x) {
                text.setPosition(-text.getLocalBounds().width, 0);
            }
            text.move(diff, 0.f);
            break;
        case Direction::RIGHT_TO_LEFT:
            if (text.findCharacterPos(string.getSize()).x < 0) {
                text.setPosition((float)w.getSize().x, 0);
            }
            text.move(-diff, 0.f);
            break;

        }
    }
    return EXIT_SUCCESS;
}