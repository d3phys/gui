#include <SFML/Graphics.hpp>
#include "arrow.h"

void gui::arrow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
        sf::Vertex line[] = { start_, end_ };

        target.draw(line, 2, sf::Lines);

        vector dir = end_ - start_;
        dir.normalize();
        dir *= 0xf;

        vector ortho = dir.ortho();
        ortho *= 0.25f;

        sf::Vertex hatl[] = { end_, end_ + (ortho - dir) };
        sf::Vertex hatr[] = { end_, end_ - (dir + ortho) };

        target.draw(hatl, 2, sf::Lines);
        target.draw(hatr, 2, sf::Lines);
}
