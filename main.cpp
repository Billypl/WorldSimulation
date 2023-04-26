#include <iostream>
#include "Utilities/Console.h"
#include "Utilities/Random.h"
#include "Utilities/Point.h"
#include "Organisms/Plants/Plant.h"
#include "Organisms/Animals/Animal.h"
#include "World/World.h"
#include "GUI/GUI.h"

using namespace std;

int main()
{
    GUI::printToBoard('s', point(0,0));
    GUI::printToBoard('s', point(BOARD_SIZE.first,BOARD_SIZE.second));
    GUI::printBoard();
    cin.get();
}
