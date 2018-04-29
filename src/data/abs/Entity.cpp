//
// Created by Jake Billings on 4/28/18.
//

#include "Entity.h"

Entity::Entity() {}

Entity::Entity(const std::string &_id) : _id(_id) {}

const std::string &Entity::get_id() const {
    return _id;
}

void Entity::set_id(const std::string &_id) {
    Entity::_id = _id;
}

void Entity::writeExternal(std::ostream &out) const {
    writeUTF(this->get_id(), out);
}

void Entity::readExternal(std::istream &in) {
    std::string id = readUTF(in);
    this->set_id(id);
}
