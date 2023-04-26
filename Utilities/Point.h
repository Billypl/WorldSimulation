#pragma once
#include <algorithm>

class point
{

public:

    int x, y;

    point			    () {};
    explicit point	    (int x, int y);
    point&   operator=  (const point& other);
    bool   operator==   (const point& other) const;
    bool   operator!=   (const point& other) const;
    bool   isEqual	    (const point& other) const;

    void swap         ();
    void swap         (point& other);
};
