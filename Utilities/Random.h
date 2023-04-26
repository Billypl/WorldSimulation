#pragma once

#include <cstdlib>
#include <ctime>

class Random
{

private:

    Random()
    {
        srand(time(NULL));
    }

public:

    static int range(int rangeStart, int rangeEnd)
    {
        static Random r; // to make srand work
        return (rand() % (rangeEnd + 1 - rangeStart) + rangeStart);
    }

};
