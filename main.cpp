#include <iostream>
#include "Utilities/Console.h"
#include "Utilities/Random.h"
#include "Utilities/Point.h"
#include "Utilities/Utils.h"
#include "Organisms/Plants/Plant.h"
#include "Organisms/Animals/Animal.h"
#include "World/World.h"
#include "GUI/GUI.h"

using namespace std;

int main()
{
    World::Get().start();
    cin.get();
}
