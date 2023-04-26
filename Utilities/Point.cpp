#include "point.h"

point::point(int x, int y)
        : x(x), y(y) {}


point& point::operator=(const point& other)
{
    x = other.x;
    y = other.y;
    return *this;
}


bool point::operator==(const point& other) const
{
    return isEqual(other);
}


bool point::operator!=(const point& other) const
{
    return !isEqual(other);
}


bool point::isEqual(const point& other) const
{
    return (x == other.x) && (y == other.y);
}


void point::swap()
{
    std::swap(x,y);
}


void point::swap(point& other)
{
    std::swap(x, other.x);
}
