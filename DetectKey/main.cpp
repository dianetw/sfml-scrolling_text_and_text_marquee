#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow w(sf::VideoMode(400, 200), L"按鍵檢測");
    int countF = 0;
    while (w.isOpen()) {
        sf::Event evt;
        if (w.pollEvent(evt)) {
            switch (evt.type) {
            case sf::Event::Closed:
                w.close();
                break;
            case sf::Event::KeyPressed:
                // 使用者按下的是哪個鍵, 使用者是否按下指定的複合鍵
                //std::cout << evt.key.code << "(" << evt.key.shift << ")" << std::endl;
                // 使用者按下了幾次指定按鍵
                if (evt.key.code == sf::Keyboard::Key::F) {
                    countF++;
                    std::cout << countF << std::endl;
                }
                break;
            default:
                break;
            }
        }
        w.clear();
        w.display();

    }
    return EXIT_SUCCESS;
}