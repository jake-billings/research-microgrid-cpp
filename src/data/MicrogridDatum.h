/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */
#include "abs/Datum.h"
#include "MicrogridNode.h"

#ifndef RESEARCH_MICROGRID_CPP_MICROGRIDDATUM_H
#define RESEARCH_MICROGRID_CPP_MICROGRIDDATUM_H

/**
 * MicrogridDatum
 *
 * abstract class
 *
 * immutable
 *
 * This class is intended to represent one reading at one point in time from one instrument. Depending on the final
 *  protocol implementation, packets may contain multiple instances of data. Packets might only contain one datum.
 *
 * This class should fit into one INSERT call into a SQL database.
 *
 * The datum with the most recent timestamp should represent the most up-to-date reading of an instrument at a given
 *  time.
 *
 * This class is abstract because datum can have either float or boolean values. See the subclasses BooleanDatum and
 *  FloatDatum.
 *
 * Important: the _id field of a Datum should be unique to the combination of its type and measurement location
 *  as a result, data from the same measurement location and type will have the same _id but different
 *  timestamp and value; this is important for data caching in LiveMicrogrid
 *
 * A unique identifier for an individual datum object should contain its _id AND its timestamp
 *
 *  @author Jake Billings
 */
class MicrogridDatum : public Datum {
private:
    const MicrogridNode *node;

protected:
    //----Setters----
    //Setters are protected because this class is "immutable" (except for when deserializing)
    void setNode(const MicrogridNode *node);

public:
    /**
     * MicrogridDatum
     *
     * constructor: empty
     *
     * for use with deserialization; do not use for instantiation
     */
    MicrogridDatum() {};

    /**
     * MicrogridDatum
     *
     * constructor
     *
     * @param timestamp timestamp when datum was created
     * @param node node the datum was recorded at
     * @param measurementTypeId the id of the measurement type
     */
    MicrogridDatum(long timestamp, const MicrogridNode *node, char measurementTypeId);

    //----Getters----
    const MicrogridNode *getNode() const;

    void writeExternal(std::ostream &out) const;

    void readExternal(std::istream &in);
};


#endif //RESEARCH_MICROGRID_CPP_MICROGRIDDATUM_H
