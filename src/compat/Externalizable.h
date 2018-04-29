/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */
#include <iostream>

#ifndef RESEARCH_MICROGRID_CPP_EXTERNALIZABLE_H
#define RESEARCH_MICROGRID_CPP_EXTERNALIZABLE_H

/**
 * Externalizable
 *
 * abstract class (interface)
 *
 * simulation of the Externalizable interface from java;
 *  we use this to make the classes "truly match" the ones from Java
 *
 * implementations of this interface should read/write complete object state
 *  from the given streams
 */
class Externalizable {
public:
    virtual void writeExternal(std::ostream &out) const =0;

    virtual void readExternal(std::istream &in)=0;
};


#endif //RESEARCH_MICROGRID_CPP_EXTERNALIZABLE_H
