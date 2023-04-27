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

    static bool isProbable(double probability)
    {
        if(probability > 1 || probability < 0)
            throw "Wrong probability ratio";
        return range(1,100) < probability*100;
    }
};
