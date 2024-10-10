#include "ray_intersect_triangle_mesh_brute_force.h"
#include "ray_intersect_triangle.h"
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <limits>
bool ray_intersect_triangle_mesh_brute_force(
  const Ray & ray,
  const Eigen::MatrixXd & V, // #V by 3 list of mesh vertex positions
  const Eigen::MatrixXi & F, // #F by 3 list of triangle indices into rows of V
  const double min_t,
  const double max_t,
  double & hit_t, // parameteric distance of hit along ray
  int & hit_f) // index into F of triangle that was hit
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  hit_t = std::numeric_limits<double>::infinity();
  hit_f = -1;
  double t; // parametric distance along ray to hit
  bool hit = false;
  bool potential_hit = false;
  for (size_t i = 0; i < F.rows(); i ++ ){ // iterate thro indices of faces
    Eigen::Vector3d v0 = V.row(F(i, 0)); //F i-th row, 0-th col
    Eigen::Vector3d v1 = V.row(F(i, 1)); //F i-th row, 1st col
    Eigen::Vector3d v2 = V.row(F(i, 2)); //F i-th row, 2nd col
    potential_hit = ray_intersect_triangle(ray, v0, v1, v2, min_t, max_t, t);
    // if (i == 757) {
    //   std::cout << 'hit' << hit; 
    // }
    if (potential_hit && t < hit_t && min_t <= t <= max_t ) {
      hit = true;
      hit_t = t;
      hit_f = i;
      return true;
    }
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
