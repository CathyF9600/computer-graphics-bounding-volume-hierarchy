#include "ray_intersect_box.h"
#include <iostream>
#include <algorithm>

bool ray_intersect_box(
  const Ray & ray,
  const BoundingBox& box,
  const double min_t,
  const double max_t)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // Use bounding box intersection algorithm by A. Williams et al listed in
  // Section 12.3 of Fundamentals of Computer Graphics (3rd)
  double t_xmin, t_ymin, t_zmin, t_xmax, t_ymax, t_zmax;
  double x_e, y_e, z_e;
  double a_x, a_y, a_z;

  x_e = ray.origin[0];
  y_e = ray.origin[1];
  z_e = ray.origin[2];

  a_x = 1 / (ray.direction[0]);
  a_y = 1 / (ray.direction[1]);
  a_z = 1 / (ray.direction[2]);

  if (a_x >= 0){
      t_xmin = a_x * (box.min_corner[0] - x_e);
      t_xmax = a_x * (box.max_corner[0] - x_e);
  } else {
      t_xmin = a_x * (box.max_corner[0] - x_e);
      t_xmax = a_x * (box.min_corner[0] - x_e);
  }

  if (a_y >= 0){
      t_ymin = a_y * (box.min_corner[1] - y_e);
      t_ymax = a_y * (box.max_corner[1] - y_e);
  } else {
      t_ymin = a_y * (box.max_corner[1] - y_e);
      t_ymax = a_y * (box.min_corner[1] - y_e);
  }

  // Use negative a_z for min case because ray goes in negative z dir
  if (a_z >= 0){
      t_zmin = a_z * (box.min_corner[2] - z_e);
      t_zmax = a_z * (box.max_corner[2] - z_e);
  } else {
      t_zmin = a_z * (box.max_corner[2] - z_e);
      t_zmax = a_z * (box.min_corner[2] - z_e);
  }

  if (std::max({t_xmin, t_ymin, t_zmin}) <= std::min({t_xmax, t_ymax, t_zmax})) {
      // If min_t within box, treat as hit because ray could hit something inside the box
      //min_t_pt is in box if min_t is within interval
    if (std::max({t_xmin, t_ymin, t_zmin}) <= min_t && min_t <= std::min({t_xmax, t_ymax, t_zmax})) {
        return true;
    } else if (min_t <= std::max({t_xmin, t_ymin, t_zmin}) && std::max({t_xmin, t_ymin, t_zmin}) <= max_t) {
    // Intersection point is at entry point
        return true;
    } else {
        return false;
    }
  } else {
      return false;
  }

  ////////////////////////////////////////////////////////////////////////////
}