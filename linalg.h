#ifndef _linalg_h_
#define _linalg_h_

#include <cmath>
#include <SFML/Graphics.hpp>

class vector {

private:
        double x_;
        double y_;

public:
        vector()
                : x_(0),
                  y_(0)
        {};

        vector(double x, double y)
                : x_(x),
                  y_(y)
        {};

        vector(const vector& vec)
                : x_(vec.x_),
                  y_(vec.y_)
        {};

        ~vector()
        {}

        double x() const { return x_; };
        double y() const { return y_; };

        void normalize() { *this *= (1/std::sqrt(x_ * x_ + y_ * y_)); }

        vector& operator +=(const vector& rhs);
        vector& operator -=(const vector& rhs);

        vector& operator *=(double rhs);

        vector ortho() { return vector(y_, -x_); }

        friend vector operator *(vector lhs, double rhs);
        friend vector operator *(double rhs, vector lhs);

        friend vector operator +(vector lhs, const vector& rhs);
        friend vector operator -(vector lhs, const vector& rhs);
        friend vector operator -(vector lhs, const vector& rhs);

        operator sf::Vector2f() const { return sf::Vector2f(x_, y_); };
        operator sf::Vertex()   const { return sf::Vertex(sf::Vector2f(x_, y_)); };

};

#endif /* _linalg_h_ */
