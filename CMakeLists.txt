cmake_minimum_required(VERSION 3.25)
project(WorldSimulation)

set(CMAKE_CXX_STANDARD 20)

add_executable(WorldSimulation main.cpp Utilities/Console.h Utilities/Console.h Utilities/Random.h Organisms/Organism.h Utilities/Point.h Utilities/Point.cpp Organisms/Organism.cpp Organisms/Animals/Animal.cpp Organisms/Animals/Animal.h Organisms/Plants/Plant.cpp Organisms/Plants/Plant.h World/World.cpp World/World.h World/Board.cpp World/Board.h GUI/GUI.cpp GUI/GUI.h Utilities/Includes.h)
