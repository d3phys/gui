#include <SFML/Graphics.hpp>
#include "linalg.h"
#include "arrow.h"
#include "canvas.h"

int main()
{
        sf::RenderWindow window(sf::VideoMode(600, 600), "gui");

        gui::canvas canvas1(vector(200, 200), vector(100, 0), vector(0, -100));
        gui::arrow arrow1(canvas1);

        gui::canvas canvas2(vector(500, 500), vector(200, 0), vector(0, -200));
        gui::arrow arrow2(canvas2);

        gui::canvas canvas3(vector(100, 100), vector(50, 0), vector(0, -50));
        gui::arrow arrow3(canvas3);

        while (window.isOpen()) {
                sf::Event event;

                while (window.pollEvent( event)) {
                        if (event.type == sf::Event::Closed) {
                                window.close();
                        } else if (event.type == sf::Event::MouseButtonPressed) {
                                arrow1.set_abs_end(vector(event.mouseButton.x, event.mouseButton.y));
                                arrow2.set_abs_end(vector(event.mouseButton.x, event.mouseButton.y));
                                arrow3.set_abs_end(vector(event.mouseButton.x, event.mouseButton.y));
                        }
                }

                window.clear();

                window.draw(canvas1);
                window.draw(arrow1);

                window.draw(canvas2);
                window.draw(arrow2);

                window.draw(canvas3);
                window.draw(arrow3);

                window.display();
        }

        return 0;
}
