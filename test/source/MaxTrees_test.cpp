#include "lib.hpp"
#include <cassert.h>

bool testNoTreeInput()
{
  const library lib = library{};
  double personX = 3.5;
  double personY = 3.5;
  int angle = 50;
  std::vector<std::pair<double,double>> treesCoordinates;

  int expectedTrees = -1;
  int actualTrees = -1;
  lib.maxTrees(treesCoordinates, angle,std::make_pair(personX, personY), actualTrees);
  return expectedTrees == actualTrees; 
}


bool testSingleTreeInput()
{
  const library lib = library{};
  double personX = 3.5;
  double personY = 3.5;
  int angle = 50;
  std::vector<std::pair<double,double>> treesCoordinates;
  treesCoordinates.push_back(std::make_pair(0.0,0.0));

  int expectedTrees = 1;
  int actualTrees = -1;
  lib.maxTrees(treesCoordinates, angle,std::make_pair(personX, personY), actualTrees);
  return expectedTrees == actualTrees; 
}

bool testMultipleTrees()
{
  const library lib = library{};
  double personX = 1;
  double personY = 1;
  int angle = 90;
  std::vector<std::pair<double,double>> treesCoordinates;
  treesCoordinates.push_back(std::make_pair(3.0,1.0));
  treesCoordinates.push_back(std::make_pair(4.0,4.0));
  treesCoordinates.push_back(std::make_pair(3.0,4.0));
  treesCoordinates.push_back(std::make_pair(1.0,2.0));

  int expectedTrees = 4;
  int actualTrees = -1;
  lib.maxTrees(treesCoordinates, angle,std::make_pair(personX, personY), actualTrees);
  return expectedTrees == actualTrees; 
}



auto main() -> int
{
  ASSERT(testNoTreeInput());
  ASSERT(testSingleTreeInput());
  ASSERT(testMultipleTreesT1());
}
