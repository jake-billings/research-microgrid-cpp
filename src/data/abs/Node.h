/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */
#include "Entity.h"

#ifndef RESEARCH_MICROGRID_CPP_NODE_H
#define RESEARCH_MICROGRID_CPP_NODE_H

/**
 * Node
 *
 * class
 *
 * immutable
 *
 * A graph contains a set of edges and nodes. This class represents a node.
 * http://mathworld.wolfram.com/Graph.html
 *
 * My intention is for a subclass to add microgrid-specific data to this class.
 *
 * @author Jake Billings
 */
class Node : public Entity {
public:
    Node() {};
    Node(std::string _id) : Entity(_id) {};

    void writeExternal(std::ostream &out)  const {
        Entity::writeExternal(out);
    }

    void readExternal(std::istream &in)  {
        Entity::readExternal(in);
    }
};


#endif //RESEARCH_MICROGRID_CPP_NODE_H
