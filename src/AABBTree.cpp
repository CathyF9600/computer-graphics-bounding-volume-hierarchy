#include "AABBTree.h"
#include "insert_box_into_box.h"
#include <cstddef>

AABBTree::AABBTree(
  const std::vector<std::shared_ptr<Object> > & objects,
  int a_depth): 
  depth(std::move(a_depth)), 
  num_leaves(objects.size())
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  // initialize bounding box at depth = 0
  if (objects.size() <= 2) {//if there are only one or two objects
    insert_box_into_box(objects[0]->box, this->box);
    left = objects[0];
    right = nullptr;
    if (objects.size() == 2) {
      insert_box_into_box(objects[1]->box, this->box);
      right = objects[1];
    }
    return;
  }
  if (a_depth == 0) {
    this->box.max_corner = objects[0]->box.max_corner;
    this->box.min_corner = objects[0]->box.min_corner;
  }
  // iterate thro all objects and update the bounding box to eccompass all objects
  for (size_t i = 0; i < objects.size(); i ++ ) {
    insert_box_into_box(objects[i]->box, this->box); // box is from Object.h
  }
  // box lengths
  double box_x = this->box.max_corner(0) - this->box.min_corner(0);
  double box_y = this->box.max_corner(1) - this->box.min_corner(1);
  double box_z = this->box.max_corner(2) - this->box.min_corner(2);
  double longest_len = std::max({box_x, box_y, box_z});

  std::vector< std::shared_ptr<Object> > left_tree;
  std::vector< std::shared_ptr<Object> > right_tree;
  for (size_t i = 0; i < objects.size(); i ++ ) {
    if (longest_len == box_x) {
      if (objects[i]->box.center()[0] <= this->box.center()(0)) { // left of this axis
        left_tree.push_back(objects[i]);
      } else {
        right_tree.push_back(objects[i]);
      }
    }
    else if (longest_len == box_y) {
      if (objects[i]->box.center()[1] <= this->box.center()(1)) { // left of this axis
        left_tree.push_back(objects[i]);
      } else {
        right_tree.push_back(objects[i]);
      }
    }
    else if (longest_len == box_z) {
      if (objects[i]->box.center()[2] <= this->box.center()(2)) { // left of this axis
        left_tree.push_back(objects[i]);
      } else {
        right_tree.push_back(objects[i]);
      }
    }
  }
  if (left_tree.size() == 0 && right_tree.size() >= 2) {
    left_tree.push_back(right_tree.back());
    right_tree.pop_back();
  }
  if (right_tree.size() == 0 && left_tree.size() >= 2) {
    right_tree.push_back(left_tree.back());
    left_tree.pop_back();
  }
  
  // recursive calling constructor
  left = std::make_shared<AABBTree>(left_tree, depth+1);
  right = std::make_shared<AABBTree>(right_tree, depth+1);
  ////////////////////////////////////////////////////////////////////////////
}
