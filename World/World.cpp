#include "World.h"

World::World()
{

}

World &World::Get()
{
    static World world;
    return world;
}
