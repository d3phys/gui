#include "linalg.h"

vector& vector::operator +=(const vector& rhs)
{
        this->x_ += rhs.x_;
        this->y_ += rhs.y_;
        return *this;
}

vector& vector::operator -=(const vector& rhs)
{
        this->x_ -= rhs.x_;
        this->y_ -= rhs.y_;
        return *this;
}

vector operator +(vector lhs, const vector& rhs)
{
        return (lhs += rhs);
}

vector operator -(vector lhs, const vector& rhs)
{
        return (lhs -= rhs);
}

vector& vector::operator *=(double rhs)
{
       this->x_ *= rhs;
       this->y_ *= rhs;
       return *this;
}

vector operator *(double lhs, vector rhs)
{
        return (rhs *= lhs);
}

vector operator *(vector lhs, double rhs)
{
        return (lhs *= rhs);
}

