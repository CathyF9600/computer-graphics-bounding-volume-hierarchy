#include "ray_intersect_triangle.h"
#include <Eigen/src/Core/Matrix.h>
#include <iostream>
#include <Eigen/Dense>

using namespace std;
bool ray_intersect_triangle(
  const Ray & ray,
  const Eigen::RowVector3d & A,
  const Eigen::RowVector3d & B,
  const Eigen::RowVector3d & C,
  const double min_t,
  const double max_t,
  double & t) // parametric distance along ray to hit
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  //  t1 = A -> B
  //  t2 = A -> C
  // e = [t1 t2 -d].T [alpha beta t]
  // [alpha beta t] = inverse([t1 t2 -d].T) * e 
  Eigen::Vector3d t1 = (B - A).transpose();
  Eigen::Vector3d t2 = (C - A).transpose();
  Eigen::Vector3d d = ray.direction;
  Eigen::Matrix3d A_matrix;
  A_matrix << t1, t2, -d;
  
  Eigen::Vector3d e = ray.origin - A.transpose(); // ray origin relative to A

  Eigen::Vector3d lhs = A_matrix.inverse() * e;

  double alpha = lhs[0];
  double beta = lhs[1];
  t = lhs[2];

  // check normal vector direction and ray direction
  Eigen::Vector3d n = t1.cross(t2);
  if (n.dot(ray.direction) < 0) {
    // if the normal vector is opposite to the ray vector (good reflection)
    n = n.normalized();
  } else if (n.dot(ray.direction) == 0) {
    return false;
  } else {
    n = -n.normalized(); // reverse the normal vector
  }

  if ((t > min_t) && (t < max_t) && (alpha >= 0) && (beta >= 0) && (alpha + beta <= 1)) {
    // the bound
    return true;
  } else {
    return false;
  }


  ////////////////////////////////////////////////////////////////////////////
}

