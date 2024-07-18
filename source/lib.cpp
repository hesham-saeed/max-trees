#include "lib.hpp"

library::library()
    : name {"MaxTrees"}
{
}
std::pair<double,double> library::maxTrees(std::vector<std::pair<double,double>> treePositions, int angle, std::pair<double,double> location, int& retMaxTrees) const
{
    /* initialize output */
    retMaxTrees = -1;

    /* Scenario 1: Handle Invalid Input  */
    if (treePositions.size() == 0)
    {
        return std::make_pair(0,0);
    }


    /* Scenario 2: Handle Single Tree Input  */
    if (treePositions.size() == 1)
    {
        retMaxTrees = 1;
        return std::make_pair(treePositions[0].first, treePositions[0].second);
    }
        

    /* Scenario 3: Handle Multiple Trees */

    /* define vector to store angle of each tree from the person's position*/
    std::vector<int> trees_angles(treePositions.size());

    /* compute the angle between each tree's position and person's position using [arctan] */
    for (int i = 0; i < trees_angles.size(); i++)
    {
        double y = treePositions[i].second - location.second;
        double x = treePositions[i].first - location.first;

        /* Handle divison by zero */
        if (x == 0)
            trees_angles[i] = atan(y) * 180 / PI; // [*180/PI] Converts radians to degrees
        else
            trees_angles[i] = atan(y / x) * 180 / PI; 
    }

    /* Finding the maximum number of trees in a certain field of view 
    *  1. Sort the trees' coordinates by their angles O(NLogN)
    *  2. Find the set of angles that have the minimal differences between them 
    *  3. Use sliding window approach when computing differences. O(N)
    */

    /* Sort the tree positions by the angles */
    std::sort(trees_angles.begin(), trees_angles.end());


    /* Two pointers approach (sliding window) */

    int maxTrees = 1;
    int treesWithinFieldOfView = 1;
    int fieldOfViewAngle = 0;

    /* Two pointers to define final boundary of the viewing angle of the person */
    int finalLeftPointer;
    int finalRightPointer;

    /* Two pointers to define current boundary of the viewing angle of the person  */
    int leftPointer = 0;
    int rightPointer = 1;

    /* Debugging iterator */
    int it = 1;

    while (true)
    {
        //Check if the new tree fits within the person's view angel
        int temp = ((trees_angles[rightPointer] - trees_angles[rightPointer - 1]) + fieldOfViewAngle);
        if (temp <= angle)
        {
            /* Add the new tree to the result */
            //std::cout<<trees_angles[rightPointer] << " ";
            fieldOfViewAngle += trees_angles[rightPointer] - trees_angles[rightPointer - 1];
            treesWithinFieldOfView ++;

            /* Extend the sliding window */
            ++rightPointer;

            /* Check and update if the current window is bigger than the Biggest Possible Window */
            if (treesWithinFieldOfView > maxTrees)
            {
              maxTrees = treesWithinFieldOfView;
              retMaxTrees = maxTrees;
              finalLeftPointer = leftPointer;
              finalRightPointer = rightPointer;
            }
                
        }
        else
        {
            /* Tree isn't added to the results because its outside the person's view angel */
            fieldOfViewAngle -= trees_angles[leftPointer + 1] - trees_angles[leftPointer];

            /* Shrink the sliding window from the left side */
            leftPointer++;
            treesWithinFieldOfView--;
        }

        /* Stopping condition if the right pointer reaches the end of the array */
        if (rightPointer == treePositions.size())
            break;
    }
    std::pair<double,double> x_vector;
    x_vector.first = cos(trees_angles[finalLeftPointer]);
    x_vector.second = sin(trees_angles[finalLeftPointer]);

    std::pair<double,double> y_vector;
    y_vector.first = cos(trees_angles[finalRightPointer]);
    y_vector.second = sin(trees_angles[finalRightPointer]);

    std::pair<double,double> result(std::make_pair(x_vector.first + y_vector.first, x_vector.second + y_vector.second));
    return result;
}