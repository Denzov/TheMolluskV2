#ifndef THEMOLLUSK_CLUSTER_NODE_H

#define THEMOLLUSK_CLUSTER_NODE_H


#include "Shape.h"

namespace Shape {
    struct ClusterNode{
        Shape::Variant shape;
        Math::Vec2 anchor; // set position relative (0, 0)
    };
}

#endif // !THEMOLLUSK_CLUSTER_NODE_H
