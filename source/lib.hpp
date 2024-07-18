#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>


/** 
 * @brief Depending on the compiler, PI may or may not exist, hence redifinition 
 */
#ifndef PI
#define PI 3.14159265358979323846
#endif
static int AVAL = -1;

/**
 * @brief
 * A class that finds the orientation of a person such that the maximum number of trees are in his field of view.
 */
struct library
{
  /**
   * @brief Simply initializes the name member to the name of the project
   */
  library();

  std::string name;

  /**
   * @brief Compute persons orientation to find max number of trees in his field of view.
   * @brief input: Tree positions, viewing angle, person's location
   * @brief output: the person's orientation as the unit vector pointing to the desired viewing orientation
   */
  std::pair<double,double> maxTrees(std::vector<std::pair<double,double>> points, int angle, std::pair<double,double> location, int& retMaxTrees=AVAL) const;


};
