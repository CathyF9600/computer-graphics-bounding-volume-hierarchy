#include "point_box_squared_distance.h"
#include <algorithm>  // For std::max and std::min

double point_box_squared_distance(
  const Eigen::RowVector3d & query,
  const BoundingBox & box)
{
  double sqrDist = 0.0;
  
  // Iterate through each dimension (x, y, z)
  for (int i = 0; i < 3; ++i) {
    if (query[i] < box.min_corner[i]) {
      // Point is outside the box on the low side along this axis
      double diff = box.min_corner[i] - query[i];
      sqrDist += diff * diff;
    } else if (query[i] > box.max_corner[i]) {
      // Point is outside the box on the high side along this axis
      double diff = query[i] - box.max_corner[i];
      sqrDist += diff * diff;
    }
    // If the point is inside the box along this axis, no distance is added
  }

  return sqrDist;
}
