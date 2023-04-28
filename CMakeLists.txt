cmake_minimum_required(VERSION 3.25)
project(WorldSimulation)

set(CMAKE_CXX_STANDARD 20)

add_executable(WorldSimulation main.cpp Utilities/Console.h Utilities/Console.h Utilities/Random.h Organisms/Organism.h Utilities/Point.h Utilities/Point.cpp Organisms/Organism.cpp Organisms/Animals/Animal.cpp Organisms/Animals/Animal.h Organisms/Plants/Plant.cpp Organisms/Plants/Plant.h World/World.cpp World/World.h GUI/GUI.cpp GUI/GUI.h Utilities/Includes.h Utilities/Utils.h World/InputParser.cpp World/InputParser.h Organisms/Plants/Grass.cpp Organisms/Plants/Grass.h Organisms/Plants/Dandelion.cpp Organisms/Plants/Dandelion.h Organisms/Plants/Guarana.cpp Organisms/Plants/Guarana.h Organisms/Plants/Wolfberries.cpp Organisms/Plants/Wolfberries.h Organisms/Plants/SosnowskyBorscht.cpp Organisms/Plants/SosnowskyBorscht.h Organisms/Animals/Wolf.cpp Organisms/Animals/Wolf.h Organisms/Animals/Sheep.cpp Organisms/Animals/Sheep.h Organisms/Animals/Fox.cpp Organisms/Animals/Fox.h Organisms/Animals/Turtle.cpp Organisms/Animals/Turtle.h Organisms/Animals/Human.cpp Organisms/Animals/Human.h Organisms/Animals/Antelope.cpp Organisms/Animals/Antelope.h)
