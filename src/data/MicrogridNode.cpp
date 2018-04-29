/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */

#include "MicrogridNode.h"
#include "MicrogridNodeType.h"

MicrogridNode::MicrogridNode(const std::string &_id, const MicrogridNodeType &microgridNodeType) : Node(_id),
                                                                                                   microgridNodeType(
                                                                                                           microgridNodeType) {}

MicrogridNodeType MicrogridNode::getMicrogridNodeType() const {
    return microgridNodeType;
}

void MicrogridNode::setMicrogridNodeType(MicrogridNodeType microgridNodeType) {
    MicrogridNode::microgridNodeType = microgridNodeType;
}

void MicrogridNode::writeExternal(std::ostream &out) const {
    Node::writeExternal(out);
    out.write(reinterpret_cast<const char*>(&this->microgridNodeType), sizeof(MicrogridNodeType));
}

void MicrogridNode::readExternal(std::istream &in) {
    Node::readExternal(in);
    in.read(reinterpret_cast<char*>(&this->microgridNodeType), sizeof(MicrogridNodeType));
}
