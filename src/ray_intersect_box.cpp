#include "ray_intersect_box.h"
#include <algorithm>
#include <iostream>

bool ray_intersect_box(
  const Ray & ray,
  const BoundingBox& box,
  const double min_t,
  const double max_t)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double t_x_min, t_x_max, t_y_min, t_y_max, t_z_min, t_z_max;
  if (ray.origin[0] >= 0) {
      t_x_min = (box.min_corner(0) - ray.origin(0)) / ray.direction(0);
      t_x_max = (box.max_corner(0) - ray.origin(0)) / ray.direction(0);
  } else {
      t_x_min = (box.max_corner(0) - ray.origin(0)) / ray.direction(0);
      t_x_max = (box.min_corner(0) - ray.origin(0)) / ray.direction(0);
  }
  if (ray.origin[1] >= 0) {
    t_y_min = (box.min_corner(1) - ray.origin(1)) / ray.direction(1);
    t_y_max = (box.max_corner(1) - ray.origin(1)) / ray.direction(1);
  } else { 
    t_y_min = (box.max_corner(1) - ray.origin(1)) / ray.direction(1);
    t_y_max = (box.min_corner(1) - ray.origin(1)) / ray.direction(1);
  }
  if (ray.origin[2] >= 0) {
    t_z_min = (box.min_corner(2) - ray.origin(2)) / ray.direction(2);
    t_z_max = (box.max_corner(2) - ray.origin(2)) / ray.direction(2);
  } else {
    t_z_min = (box.max_corner(2) - ray.origin(2)) / ray.direction(2);
    t_z_max = (box.min_corner(2) - ray.origin(2)) / ray.direction(2);
  }
  double max_of_min = std::max({t_x_min, t_y_min, t_z_min});
  double min_of_max = std::min({ t_x_max, t_y_max, t_z_max});
  if (max_of_min > min_of_max) {
    if ((max_of_min <= min_t <= min_of_max)) {    // inside of the box
      return true;
    } else if (min_t <= max_of_min && min_of_max <= max_t) { // intersection
      return true;
    }
  }

  // intersect if max
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
