#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow w(sf::VideoMode(400, 200), L"�����˴�");
    int countF = 0;
    while (w.isOpen()) {
        sf::Event evt;
        if (w.pollEvent(evt)) {
            switch (evt.type) {
            case sf::Event::Closed:
                w.close();
                break;
            case sf::Event::KeyPressed:
                // �ϥΪ̫��U���O������, �ϥΪ̬O�_���U���w���ƦX��
                //std::cout << evt.key.code << "(" << evt.key.shift << ")" << std::endl;
                // �ϥΪ̫��U�F�X�����w����
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