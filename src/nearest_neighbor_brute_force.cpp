#include "nearest_neighbor_brute_force.h"
#include <limits> // for std::numeric_limits<double>::infinity()
#include <cmath>  // for std::pow and std::sqrt

void nearest_neighbor_brute_force(
  const Eigen::MatrixXd & points,
  const Eigen::RowVector3d & query,
  int & I,
  double & sqrD)
{
  // Initialize the closest distance to infinity, and index to -1
  sqrD = std::numeric_limits<double>::infinity();
  I = -1;

  // Loop through each point in the 'points' matrix
  for (int i = 0; i < points.rows(); ++i)
  {
    // Calculate the squared Euclidean distance from the query to the current point
    double current_sqrD = (points.row(i) - query).squaredNorm();

    // If the current distance is smaller than the best so far, update sqrD and I
    if (current_sqrD < sqrD)
    {
      sqrD = current_sqrD;
      I = i;
    }
  }
}
