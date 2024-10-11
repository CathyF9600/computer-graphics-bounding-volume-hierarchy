#include "point_AABBTree_squared_distance.h"
#include "point_box_squared_distance.h"
#include "Object.h"
#include <queue> // std::priority_queue
// #include <algorithm>
#include <cmath>

typedef std::pair<double, std::shared_ptr<Object>> pqPair;

bool point_AABBTree_squared_distance(
    const Eigen::RowVector3d & query,
    const std::shared_ptr<AABBTree> & root,
    const double min_sqrd,
    const double max_sqrd,
    double & sqrd,
    std::shared_ptr<Object> & descendant)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here
  sqrd = max_sqrd;

  // initialize a queue prioritized by minimum distance
  double sqDist = point_box_squared_distance(query, root -> box);

  std::priority_queue<pqPair, std::vector<pqPair>, std::greater<pqPair> > pq;
  pq.push(std::make_pair(sqDist, root));

  double d_sb, d_s, d_l, d_r;
  std::shared_ptr<Object> subTree;

  pqPair current;
  while (pq.size() != 0) {
    current = pq.top();
    d_sb = current.first;
    subTree = current.second;
    pq.pop();

    if (d_sb < sqrd) {
      std::shared_ptr<AABBTree> aabbTree = std::dynamic_pointer_cast<AABBTree>(subTree);
      if (!aabbTree || (!(aabbTree -> left) && !(aabbTree -> right))) { 
        //If this->left is actually pointing to an instance of AABBTree, the cast will succeed. If not, it 
        // will return a nullptr instead of throwing an error, making it safer than other types of casts. 
        // i.e. if current node is a leaf (not a AABBTree, but just an object), it will be nullptr
        subTree -> point_squared_distance(query, min_sqrd, max_sqrd, d_s, descendant);
        sqrd = std::fmin(sqrd, d_s);
        descendant = subTree;
      } else {
        if (aabbTree -> left) {
          d_l = point_box_squared_distance(query, aabbTree -> left -> box);
          pq.push(std::make_pair(d_l, aabbTree -> left));
        }
        if (aabbTree -> right) {
          d_r = point_box_squared_distance(query, aabbTree -> right -> box);
          pq.push(std::make_pair(d_r, aabbTree -> right));
        }
      }
    }
  }

  return (sqrd >= min_sqrd && sqrd < max_sqrd);
  ////////////////////////////////////////////////////////////////////////////
}