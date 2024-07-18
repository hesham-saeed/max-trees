#include <iostream>
#include <string>
#include <vector>

#include "lib.hpp"

auto main() -> int
{
  double personX,personY;
  int angle;
  int trees;
  std::cout << "Input: the following (personX, personY, angle): ";
  std::cin >> personX >> personY >> angle;

  std::vector<std::pair<double,double>> treesCoordinates;
  std::cout << "Input: the number of trees: ";
  std::cin>> trees;
  int v = 1;

  while (trees--)
  {
    double treeX, treeY;
    std::cout << "Input: Tree #" << v++ << " position (x,y): " ;
    std::cin >> treeX >> treeY;
    treesCoordinates.push_back(std::make_pair(treeX,treeY));
  }
  const library lib = library {};
  int outputTrees = -1;
  std::pair<double,double> personsOrientation = lib.maxTrees(treesCoordinates, angle, std::make_pair(personX,personY), outputTrees);
  std::cout<< "Max number of viewable trees = " << outputTrees <<std::endl;
  std::cout<< "Person's orientation unit vector (x,y) = " << personsOrientation.first << " " << personsOrientation.second<<std::endl;
  return 0;
}
