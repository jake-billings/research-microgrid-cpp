/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */
#include <string>

#include "../../compat/Externalizable.h"
#include "../../compat/utf.h"

#ifndef RESEARCH_MICROGRID_CPP_ENTITY_H
#define RESEARCH_MICROGRID_CPP_ENTITY_H

/**
 * Entity
 *
 * immutable
 *
 * All data objects for this project will have unique _ids. Objects should always be compared using these ids.
 *  I do not specify how to create this unique id or enforce its uniquness. However, the system will break if it
 *  is not unique for each object.
 *
 *  I recommend using UUID4 for this.
 *
 * Example subclasses: Graph, Node, Edge, Datum
 *
 * @author Jake Billings
 */
class Entity : public Externalizable {
private:
    /**
     * _id
     *
     * string
     *
     * unique string identifier for this entity; must be globally unique; uuid_4 is a good option
     */
    std::string _id;

protected:
    //----Setters----
    //Setters are protected because this class is "immutable" (except for when deserializing)
    void set_id(const std::string &_id);

public:
    /**
     * Entity
     *
     * constructor: empty
     *
     * for use with deserialization; do not use for instantiation
     */
    Entity();

    /**
     * Entity()
     *
     * superconstructor for all entities; requires a uniuqe _id param
     *
     * @param _id a uniuqe string _id for this entity
     */
    Entity(const std::string &_id);

    //----Getters----
    const std::string &get_id() const;

    //----Externalizers----
    void writeExternal(std::ostream &out) const;

    void readExternal(std::istream &in);
};


#endif //RESEARCH_MICROGRID_CPP_ENTITY_H
