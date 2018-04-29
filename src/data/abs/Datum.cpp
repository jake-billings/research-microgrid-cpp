//
// Created by Jake Billings on 4/28/18.
//

#include "Datum.h"

Datum::Datum(std::string _id, long timestamp) : Entity(_id), timestamp(timestamp) {}

void Datum::setTimestamp(long timestamp) {
    Datum::timestamp = timestamp;
}

long Datum::getTimestamp() const {
    return timestamp;
}

void Datum::writeExternal(std::ostream &out) const {
    Entity::writeExternal(out);
    long networkOrderTimestamp = swap64(this->getTimestamp());
    out.write(reinterpret_cast<const char*>(&networkOrderTimestamp), sizeof(long));
}

void Datum::readExternal(std::istream &in) {
    Entity::readExternal(in);
    long networkOrderTimestamp;
    in.read(reinterpret_cast<char*>(&networkOrderTimestamp), sizeof(long));
    this->setTimestamp(swap64(networkOrderTimestamp));
}
