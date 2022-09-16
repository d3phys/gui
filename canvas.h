#ifndef _canvas_h_
#define _canvas_h_

#include "linalg.h"
#include <SFML/Graphics.hpp>

namespace gui {

class canvas: public sf::Drawable {

private:
        const vector origin_;
        const vector x_axis_;
        const vector y_axis_;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
        vector transform(const vector& pos) const;

        canvas(const vector &origin, const vector &x_axis, const vector &y_axis)
                : origin_(origin),
                  x_axis_(x_axis),
                  y_axis_(y_axis)
        {}

        ~canvas()
        {}

};

} /* namespace gui */

#endif /* _canvas_h_ */
