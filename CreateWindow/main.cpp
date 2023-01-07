#include <SFML/Window.hpp>  // 標頭檔 (header file)
#include <SFML/Graphics.hpp>
#include <iostream>
int main() {
    // 命名空間 (namespace), 關鍵字 (keyword), 識別符 (identifier) => 名稱
//    int x = 10.5;  // double 隱性轉型成 int, 但會出現warning
//    x = x + 4;
    // sf::String title = sf::String("Hello");
    // sf::String title = "Hello";
    // sf::String::String("Hello"), 如果建構值只有一個參數, 它可以隱性轉型
    // ""的格式, 唯讀的字元陣列or字元指標, 它可以隱性轉型成一個string

    sf::Font font;
    if (font.loadFromFile("arial.ttf") == false) {
        return EXIT_FAILURE;
    }

    sf::Text text("Hello", font);

    sf::RenderWindow w(sf::VideoMode(400, 200), "Hello");  // class => type, sf::String可省略
                                                           // sf::Window::Window() : 初始化
//    int frameNum = 0;
    while (w.isOpen()) {
        sf::Event evt;
        if (w.pollEvent(evt)) {
            // evt 存放著使用者互動發生的事件
            if (evt.type == sf::Event::Closed) {
                w.close();
            }
        }
        w.clear();
        /* methond 2 直接設定文字 (Text) 的位置 */
//        double x = frameNum * 0.01;
//        text.setPosition(x, 0);
        w.draw(text);
        w.display();
//        std::cout << "Frame #" << frameNum << ", " << x << std::endl;
        /* method 1 印出目前所在的幀數 */
        if (text.getPosition().x > 400) {
            text.setPosition(0, 0);
        }
        text.move(0.01f, 0.f);
        std::cout << "(" << text.getPosition().x << ", " << text.getPosition().y << ")" << std::endl;
//        frameNum++;
    }
    return EXIT_SUCCESS;
}