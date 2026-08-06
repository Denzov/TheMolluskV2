#ifndef THEMOLLUSK_SHAPE_CLUSTER_H
#define THEMOLLUSK_SHAPE_CLUSTER_H

#include <vector>

#include "ClusterNode.h"

namespace Shape{
    class Cluster {
    public:
        Cluster& add(Shape::ClusterNode);
        ClusterNode getBounds() const;
        const std::vector<Shape::ClusterNode>& getNodes() const;

    private:
        ClusterNode _get_rebuilt_bounds();

    private:
        ClusterNode _bounds;
        std::vector<Shape::ClusterNode> _nodes;
    };

    bool intersect(const Cluster&, Math::Vec2, const Cluster&, Math::Vec2);
}

#endif // !THEMOLLUSK_SHAPE_CLUSTER_H