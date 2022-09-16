#ifndef _arrow_h_
#define _arrow_h_

#include "linalg.h"
#include "canvas.h"

#include <SFML/Graphics.hpp>

namespace gui {

class arrow: public sf::Drawable {

private:
        const gui::canvas* canvas_;

        vector start_;
        vector end_;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
        vector get_start() { return start_; }
        vector get_end()   { return   end_; }

        void set_start(const vector& start) { start_ = canvas_->transform(start); }
        void set_end  (const vector& end)   { end_   = canvas_->transform(end);   }

        void set_abs_start(const vector& start) { start_ = start; }
        void set_abs_end  (const vector& end)   { end_   = end;   }

        arrow(const gui::canvas& canvas)
                : canvas_(&canvas),
                  start_(canvas.transform(vector(0, 0))),
                  end_  (canvas.transform(vector(0, 0)))
        {}

        arrow(const gui::canvas& canvas, const vector& start, const vector& end)
                : canvas_(&canvas),
                  start_(canvas.transform(start)),
                  end_  (canvas.transform(end))
        {}

        ~arrow()
        {}

};

} /* namespace gui */

#endif /* _arrow_h_ */
