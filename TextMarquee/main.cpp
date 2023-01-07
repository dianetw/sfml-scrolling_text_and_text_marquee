#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>  //std::stringstream

int main()
{
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return EXIT_FAILURE;
    }
    enum class Direction { GO_RIGHT, GO_LEFT };
    enum class Speed { SLOW, S2, S3, S4, FAST, DOUBLE, HALF, NONE };

    Direction direction = Direction::GO_RIGHT;
    Speed speed = Speed::SLOW;

    std::string filename("input.txt");
    std::fstream file;
    file.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);  // open file
    if (!file.is_open()) {  // check if file is open
        std::cout << "Error opening file" << std::endl;
    }
    std::stringstream strStream;
    strStream << file.rdbuf(); // read the file
    std::string str = strStream.str(); // str holds the content of the file

    sf::String string(str);
    sf::Text text(string, font, 200);
    sf::Color color(0, 255, 0);  // default color is green
    text.setFillColor(color);  // r,g,b,a range[0, 255]

    sf::CircleShape circle(2);
    circle.setFillColor(sf::Color(0, 0, 0));

    sf::RenderWindow w(sf::VideoMode(600, 250), "SFML Window");
    if (direction == Direction::GO_LEFT) {
        text.setPosition((float)w.getSize().x, 0);
    }

    float diff = 0.f;  // speed
    while (w.isOpen()) {
        sf::Event evt;
        if (w.pollEvent(evt)) {
            switch (evt.type) {
            case sf::Event::Closed:
                w.close();
                break;
            case sf::Event::KeyPressed:
                switch (evt.key.code) {
                case sf::Keyboard::Key::Left:
                    direction = Direction::GO_LEFT;
                    break;
                case sf::Keyboard::Key::Right:
                    direction = Direction::GO_RIGHT;
                    break;
                case sf::Keyboard::Key::F:
                case sf::Keyboard::Key::Num5:
                case sf::Keyboard::Key::Numpad5:
                    speed = Speed::FAST;
                    break;
                case sf::Keyboard::Key::Num4:
                case sf::Keyboard::Key::Numpad4:
                    speed = Speed::S4;
                    break;
                case sf::Keyboard::Key::Num3:
                case sf::Keyboard::Key::Numpad3:
                    speed = Speed::S3;
                    break;
                case sf::Keyboard::Key::Num2:
                case sf::Keyboard::Key::Numpad2:
                    speed = Speed::S2;
                    break;
                case sf::Keyboard::Key::S:
                case sf::Keyboard::Key::Num1:
                case sf::Keyboard::Key::Numpad1:
                    speed = Speed::SLOW;
                    break;
                case sf::Keyboard::Key::Add:
                    speed = Speed::DOUBLE;
                    break;
                case sf::Keyboard::Key::Subtract:
                    speed = Speed::HALF;
                    break;
                case sf::Keyboard::Key::R:
                    color = sf::Color(255, 0, 0);
                    break;
                case sf::Keyboard::Key::G:
                    color = sf::Color(0, 255, 0);
                    break;
                case sf::Keyboard::Key::B:
                    color = sf::Color(0, 0, 255);
                    break;
                case sf::Keyboard::Key::Y:
                    color = sf::Color(255, 255, 0);
                    break;
                }
                if (evt.key.shift) {
                    if (evt.key.code == sf::Keyboard::Key::Equal) {  // shift +
                        speed = Speed::DOUBLE;
                    }
                } else {
                    if (evt.key.code == sf::Keyboard::Key::Hyphen) {
                        speed = Speed::HALF;
                    }
                }
                break;
            default:
                break;
            }
        }
        w.clear();
        text.setFillColor(color);
        w.draw(text);
        for (unsigned int i = 0; i < w.getSize().x; i += 4) {
            for (unsigned int j = 0; j < w.getSize().y; j += 4) {
                circle.setPosition((float)i, (float)j);
                w.draw(circle);
            }
        }
        w.display();

        switch (speed) {
        case Speed::FAST:
            diff = 32.f;
            break;
        case Speed::S4:
            diff = 16.f;
            break;
        case Speed::S3:
            diff = 8.f;
            break;
        case Speed::S2:
            diff = 4.f;
            break;
        case Speed::SLOW:
            diff = 1.f;
            break;
        case Speed::DOUBLE:
            diff *= 2;
            if (diff > 32.f) diff = 32.f;
            speed = Speed::NONE;
            break;
        case Speed::HALF:
            diff /= 2;
            if (diff < 1.f) diff = 1.f;
            speed = Speed::NONE;
            break;
        }

        switch (direction) {
        case Direction::GO_RIGHT:
            if (text.getPosition().x > w.getSize().x) {
                text.setPosition(-text.getLocalBounds().width, 0);
            }
            text.move(diff, 0.f);
            break;
        case Direction::GO_LEFT:
            if (text.findCharacterPos(string.getSize()).x < 0) {
                text.setPosition((float)w.getSize().x, 0);
            }
            text.move(-diff, 0.f);
            break;
        }
        //std::cout << "current speed: " << diff << std::endl;
    }
    return EXIT_SUCCESS;
}