#include "find_all_intersecting_pairs_using_AABBTrees.h"
#include "box_box_intersect.h"
#include <list> // std::list
#include <utility>

void find_all_intersecting_pairs_using_AABBTrees(
  const std::shared_ptr<AABBTree> & rootA,
  const std::shared_ptr<AABBTree> & rootB,
  std::vector<std::pair<std::shared_ptr<Object>, std::shared_ptr<Object>>> & 
    leaf_pairs)
{
  // if (!rootA || !rootB) return; // Ensure roots are valid

  // Use a queue for BFS traversal
  std::list<std::pair<std::shared_ptr<Object>, std::shared_ptr<Object>>> queue;
  if (box_box_intersect(rootA->box, rootB->box)) {
    queue.push_back(std::make_pair(rootA, rootB));
  }

  // BFS loop
  while (!queue.empty()) {
    // Get the next pair of nodes from the queue
    auto current_pair = queue.front();
    queue.pop_front();

    auto nodeA = current_pair.first;
    auto nodeB = current_pair.second;
    auto nodeA_tree = std::dynamic_pointer_cast<AABBTree>(nodeA); // null if leaf node
    auto nodeB_tree = std::dynamic_pointer_cast<AABBTree>(nodeB);
    if (!nodeA_tree && !nodeB_tree) { //if both A and B are leaf nodes
      leaf_pairs.push_back(std::make_pair(nodeA, nodeB));
    } else if (!nodeA_tree) { // only A is a leaf nodes
      if (nodeB_tree->left != nullptr) { // a tree node could have a nullptr child
        if (box_box_intersect(nodeA->box, nodeB_tree->left->box)) {
          queue.push_back(std::make_pair(nodeA, nodeB_tree->left));
        }
      }
      if (nodeB_tree->right != nullptr) {
        if (box_box_intersect(nodeA->box, nodeB_tree->right->box)) {
          queue.push_back(std::make_pair(nodeA, nodeB_tree->right));
        }
      }
    } else if (!nodeB_tree) { // only B is a leaf nodes
      if (nodeA_tree->left != nullptr) {
        if (box_box_intersect(nodeB->box, nodeA_tree->left->box)) {
          queue.push_back(std::make_pair(nodeA_tree->left, nodeB)); // the order matters, have to be (A, B)
        }
      }
      if (nodeA_tree->right != nullptr) {
        if (box_box_intersect(nodeB->box, nodeA_tree->right->box)) {
          queue.push_back(std::make_pair(nodeA_tree->right, nodeB));
        }
      }
    } else {
      if ((nodeA_tree->left != nullptr) && (nodeB_tree->left != nullptr)) {
        if (box_box_intersect(nodeA_tree -> left -> box, nodeB_tree -> left -> box)) {
          queue.push_back(std::make_pair(nodeA_tree -> left, nodeB_tree -> left));
        }
      }
      if ((nodeA_tree->left != nullptr) && (nodeB_tree->right != nullptr)) {
        if (box_box_intersect(nodeA_tree ->left -> box, nodeB_tree -> right -> box)) {
          queue.push_back(std::make_pair(nodeA_tree -> left, nodeB_tree -> right));
        }
      }
      if ((nodeA_tree->right != nullptr) && (nodeB_tree->left != nullptr)) {
        if (box_box_intersect(nodeA_tree -> right -> box, nodeB_tree -> left -> box)) {
          queue.push_back(std::make_pair(nodeA_tree -> right, nodeB_tree -> left));
        }
      }
      if ((nodeA_tree->right != nullptr) && (nodeB_tree->right != nullptr)) {
        if (box_box_intersect(nodeA_tree -> right -> box, nodeB_tree -> right -> box)) {
          queue.push_back(std::make_pair(nodeA_tree -> right, nodeB_tree -> right));
        }
      }
    }
  }
   
}
