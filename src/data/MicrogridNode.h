/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */
#include "abs/Node.h"
#include "MicrogridNodeType.h"

#ifndef RESEARCH_MICROGRID_CPP_MICROGRIDNODE_H
#define RESEARCH_MICROGRID_CPP_MICROGRIDNODE_H

/**
 * MicrogridNode
 *
 * class
 *
 * immutable
 *
 * subclass of Node with microgrid-specific data
 *
 * @author Jake Billings
 */
class MicrogridNode : public Node {
private:
    /**
     * microgridNodeType
     *
     * MicrogridNodeType
     *
     * Each node in the network has a type that does not affect its behavior in this code. For instance, a node can be a
     *  battery, controller, or generator. The purpose of this section of code is to render the network, so we don't
     *  treat these elements with different logic. Thus, we implement their type as an enum.
     */
    MicrogridNodeType microgridNodeType;

protected:
    //----Setters----
    //Setters are protected because this class is "immutable" (except for when deserializing)
    void setMicrogridNodeType(MicrogridNodeType microgridNodeType);

public:
    /**
     * MicrogridGraph
     *
     * constructor: empty
     *
     * for use with deserialization; do not use for instantiation
     */
    MicrogridNode() {};

    MicrogridNode(const std::string &_id, const MicrogridNodeType &microgridNodeType);

    //----Getters----
    MicrogridNodeType getMicrogridNodeType() const;

    //----Externalizers----
    void writeExternal(std::ostream &out)  const;

    void readExternal(std::istream &in);
};


#endif //RESEARCH_MICROGRID_CPP_MICROGRIDNODE_H
