#include <SFML/Window.hpp>  // ���Y�� (header file)
#include <SFML/Graphics.hpp>
#include <iostream>
int main() {
    // �R�W�Ŷ� (namespace), ����r (keyword), �ѧO�� (identifier) => �W��
//    int x = 10.5;  // double �����૬�� int, ���|�X�{warning
//    x = x + 4;
    // sf::String title = sf::String("Hello");
    // sf::String title = "Hello";
    // sf::String::String("Hello"), �p�G�غc�ȥu���@�ӰѼ�, ���i�H�����૬
    // ""���榡, ��Ū���r���}�Cor�r������, ���i�H�����૬���@��string

    sf::Font font;
    if (font.loadFromFile("arial.ttf") == false) {
        return EXIT_FAILURE;
    }

    sf::Text text("Hello", font);

    sf::RenderWindow w(sf::VideoMode(400, 200), "Hello");  // class => type, sf::String�i�ٲ�
                                                           // sf::Window::Window() : ��l��
//    int frameNum = 0;
    while (w.isOpen()) {
        sf::Event evt;
        if (w.pollEvent(evt)) {
            // evt �s��ۨϥΪ̤��ʵo�ͪ��ƥ�
            if (evt.type == sf::Event::Closed) {
                w.close();
            }
        }
        w.clear();
        /* methond 2 �����]�w��r (Text) ����m */
//        double x = frameNum * 0.01;
//        text.setPosition(x, 0);
        w.draw(text);
        w.display();
//        std::cout << "Frame #" << frameNum << ", " << x << std::endl;
        /* method 1 �L�X�ثe�Ҧb���V�� */
        if (text.getPosition().x > 400) {
            text.setPosition(0, 0);
        }
        text.move(0.01f, 0.f);
        std::cout << "(" << text.getPosition().x << ", " << text.getPosition().y << ")" << std::endl;
//        frameNum++;
    }
    return EXIT_SUCCESS;
}