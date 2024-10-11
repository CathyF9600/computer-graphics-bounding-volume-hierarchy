#include "AABBTree.h"
#include "ray_intersect_box.h"

// See AABBTree.h for API
bool AABBTree::ray_intersect(
  const Ray& ray,
  const double min_t,
  const double max_t,
  double & t,
  std::shared_ptr<Object> & descendant) const 
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  t = 0;
  std::shared_ptr<Object> left_descendant, right_descendant;
  bool hit = ray_intersect_box(ray, this->box, min_t, max_t);
  bool left_is_hit, right_is_hit;
  if (hit) {
    double t_l, t_r;
    left_is_hit = (this->left!= nullptr) && (this->left->ray_intersect(ray, min_t, max_t, t_l, left_descendant));

    right_is_hit = (this->right!= nullptr) && (this->right->ray_intersect(ray, min_t, max_t, t_r, right_descendant));
  
   if (left_is_hit && (std::dynamic_pointer_cast<AABBTree>(this->left) == nullptr)) { // meaning the next node is a leaf node, not a tree branch
      left_descendant = this->left;
    }
    if (right_is_hit && (std::dynamic_pointer_cast<AABBTree>(this->right) == nullptr)) {
      right_descendant = this->right;
    }
    if (left_is_hit && right_is_hit) {
      if (t_l <= t_r) { // hit the left tree first
        t = t_l;
        descendant = left_descendant;
      } else {
        t = t_r;
        descendant = right_descendant;
      }
      return true;
    } else if (left_is_hit) {
      t = t_l;
      descendant = left_descendant;
      return true;
    } else if (right_is_hit) {
      t = t_r;
      descendant = right_descendant;
      return true;
    } else {
      t = 0;
      return false;
    }
  } else {
    t = 0;
    return false;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}

