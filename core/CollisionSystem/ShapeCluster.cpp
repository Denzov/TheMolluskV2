#include "ShapeCluster.h"

#include <raylib.h>
#include <limits>

namespace Shape{
    Cluster& Cluster::add(Shape::ClusterNode node){
        _nodes.push_back(node);
        _bounds = _get_rebuilt_bounds();

        return *this;
    }

    ClusterNode Shape::Cluster::getBounds() const {
        return _bounds;
    }

    const std::vector<Shape::ClusterNode>& Shape::Cluster::getNodes() const {
        return _nodes;
    }

    ClusterNode Cluster::_get_rebuilt_bounds(){
        float left   =  std::numeric_limits<float>::infinity();
        float top    =  std::numeric_limits<float>::infinity();
        float right  = -std::numeric_limits<float>::infinity();;
        float bottom = -std::numeric_limits<float>::infinity();;

        for(const auto& node : _nodes){
            const Shape::AABB bounds = getShapeBounds(node.shape);
            const Math::Vec2 pos = node.anchor;
            left   = std::min(left, pos.x - bounds.width / 2);
            top    = std::min(top, pos.y - bounds.height / 2);
            right  = std::max(right, pos.x + bounds.width / 2);
            bottom = std::max(bottom, pos.y + bounds.height / 2);
        }

        ClusterNode upd_bounds{
            .shape = Shape::AABB{
                .width = right - left,
                .height = bottom - top
            },
            .anchor = {
                .x = (left + right) / 2,
                .y = (bottom + top) / 2
            }
        };

        return upd_bounds;
    }

    bool intersect(
        const Cluster& c1, Math::Vec2 p1, 
        const Cluster& c2, Math::Vec2 p2)
    {
        if(!Shape::intersect(
            c1.getBounds().shape, p1 + c1.getBounds().anchor, 
            c2.getBounds().shape, p2 + c2.getBounds().anchor))
                return false;

        for(const auto& node1 : c1.getNodes()){
            for(const auto& node2 : c2.getNodes()){
                const Math::Vec2 res_pos1 = node1.anchor + p1;
                const Math::Vec2 res_pos2 = node2.anchor + p2;

                if(Shape::intersect(
                    node1.shape, res_pos1, 
                    node2.shape, res_pos2)) return true;
            }
        }

        return false;
    }
}