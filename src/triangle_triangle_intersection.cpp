#include "triangle_triangle_intersection.h"
#include <Eigen/Dense>
#include <algorithm>
#include <limits>

// Helper function to find the min and max values for the bounding box of a triangle
void find_min_max(const Eigen::RowVector3d& v0, const Eigen::RowVector3d& v1, const Eigen::RowVector3d& v2, 
                  Eigen::RowVector3d& min, Eigen::RowVector3d& max) {
    min = v0.cwiseMin(v1).cwiseMin(v2);
    max = v0.cwiseMax(v1).cwiseMax(v2);
}

// Test whether two triangles intersect using bounding box checks and edge intersection tests
bool triangle_triangle_intersection(
    const Eigen::RowVector3d& A0, const Eigen::RowVector3d& A1, const Eigen::RowVector3d& A2,
    const Eigen::RowVector3d& B0, const Eigen::RowVector3d& B1, const Eigen::RowVector3d& B2) 
{
    // Step 1: Quick rejection using bounding boxes
    Eigen::RowVector3d minA, maxA, minB, maxB;
    find_min_max(A0, A1, A2, minA, maxA);
    find_min_max(B0, B1, B2, minB, maxB);

    // If bounding boxes don't overlap, triangles don't intersect
    if ((maxA(0) < minB(0)) || (maxB(0) < minA(0)) ||
        (maxA(1) < minB(1)) || (maxB(1) < minA(1)) ||
        (maxA(2) < minB(2)) || (maxB(2) < minA(2))) {
        return false;
    }

    // Step 2: Plane tests - check if triangles lie on different sides of each other's planes
    Eigen::RowVector3d N1 = (A1 - A0).cross(A2 - A0); // Plane normal for triangle A
    Eigen::RowVector3d N2 = (B1 - B0).cross(B2 - B0); // Plane normal for triangle B

    double dA0 = N1.dot(B0 - A0), dA1 = N1.dot(B1 - A0), dA2 = N1.dot(B2 - A0);
    double dB0 = N2.dot(A0 - B0), dB1 = N2.dot(A1 - B0), dB2 = N2.dot(A2 - B0);

    // If all vertices of triangle B are on the same side of the plane of triangle A, no intersection
    if ((dA0 > 0 && dA1 > 0 && dA2 > 0) || (dA0 < 0 && dA1 < 0 && dA2 < 0)) {
        return false;
    }

    // If all vertices of triangle A are on the same side of the plane of triangle B, no intersection
    if ((dB0 > 0 && dB1 > 0 && dB2 > 0) || (dB0 < 0 && dB1 < 0 && dB2 < 0)) {
        return false;
    }

    // Step 3: Edge-edge intersection test (simplified check using separating axis theorem)
    Eigen::RowVector3d edgesA[] = {A1 - A0, A2 - A1, A0 - A2};
    Eigen::RowVector3d edgesB[] = {B1 - B0, B2 - B1, B0 - B2};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Eigen::RowVector3d axis = edgesA[i].cross(edgesB[j]);

            double projA0 = axis.dot(A0);
            double projA1 = axis.dot(A1);
            double projA2 = axis.dot(A2);

            double projB0 = axis.dot(B0);
            double projB1 = axis.dot(B1);
            double projB2 = axis.dot(B2);

            double minA = std::min({projA0, projA1, projA2});
            double maxA = std::max({projA0, projA1, projA2});
            double minB = std::min({projB0, projB1, projB2});
            double maxB = std::max({projB0, projB1, projB2});

            // Check for overlap on the axis
            if (maxA < minB || maxB < minA) {
                return false;
            }
        }
    }

    // If no separating axis is found, the triangles intersect
    return true;
}
