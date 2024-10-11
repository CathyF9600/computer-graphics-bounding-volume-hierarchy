#include "box_box_intersect.h"

// Determine if two bounding boxes intersect
bool box_box_intersect(
  const BoundingBox & A,
  const BoundingBox & B)
{
  // Check for overlap in the x-dimension
  bool x_overlap = (A.max_corner(0) >= B.min_corner(0)) && (B.max_corner(0) >= A.min_corner(0));
  
  // Check for overlap in the y-dimension
  bool y_overlap = (A.max_corner(1) >= B.min_corner(1)) && (B.max_corner(1) >= A.min_corner(1));
  
  // Check for overlap in the z-dimension
  bool z_overlap = (A.max_corner(2) >= B.min_corner(2)) && (B.max_corner(2) >= A.min_corner(2));
  
  // Boxes intersect if they overlap in all three dimensions
  return x_overlap && y_overlap && z_overlap;
}
