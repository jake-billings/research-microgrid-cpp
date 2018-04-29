/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */

#ifndef RESEARCH_MICROGRID_CPP_MICROGRIDNODETYPE_H
#define RESEARCH_MICROGRID_CPP_MICROGRIDNODETYPE_H

/**
 * MicrogridNodeType
 *
 * enum
 *
 * Each node in the network has a type that does not affect its behavior in this code. For instance, a node can be a
 *  battery, controller, or generator. The purpose of this section of code is to render the network, so we don't
 *  treat these elements with different logic. Thus, we implement their type as an enum.
 *
 * @author Jake Billings
 */
enum MicrogridNodeType: char {
    GENERATOR=1,
    BATERY=2,
    LOAD=3,
    CIRCUIT_BREAKER=4,
    HUB=5
};

#endif //RESEARCH_MICROGRID_CPP_MICROGRIDNODETYPE_H
