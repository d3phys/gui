#include "canvas.h"
#include "arrow.h"

vector gui::canvas::transform(const vector& coords) const
{
        return this->origin_ + (coords.x() * this->x_axis_) +
                               (coords.y() * this->y_axis_);
}

void gui::canvas::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
        gui::arrow x_axis(*this, vector(0, 0), vector(1, 0));
        gui::arrow y_axis(*this, vector(0, 0), vector(0, 1));

        target.draw(x_axis);
        target.draw(y_axis);
}
