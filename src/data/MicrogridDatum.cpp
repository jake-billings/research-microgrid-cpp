//
// Created by Jake Billings on 4/28/18.
//
#include <sstream>

#include "MicrogridDatum.h"
#include "MicrogridNode.h"

std::string makeId(const MicrogridNode *node, char measurementTypeId) {
    std::ostringstream s;
    s << node->get_id();
    s << '-';
    s << (int) measurementTypeId;
    return s.str();
}

MicrogridDatum::MicrogridDatum(long timestamp, const MicrogridNode *node, char measurementTypeId)
        : Datum(makeId(node, measurementTypeId), timestamp),
          node(node) {
}

const MicrogridNode *MicrogridDatum::getNode() const {
    return node;
}

void MicrogridDatum::setNode(const MicrogridNode *node) {
    MicrogridDatum::node = node;
}

void MicrogridDatum::writeExternal(std::ostream &out) const {
    Datum::writeExternal(out);
    this->getNode()->writeExternal(out);
}

void MicrogridDatum::readExternal(std::istream &in) {
    Datum::readExternal(in);
    MicrogridNode *node = new MicrogridNode();
    node->readExternal(in);
    this->setNode(node); //todo resolve memory leak
}
