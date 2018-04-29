/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */

#ifndef RESEARCH_MICROGRID_CPP_BOOLEANMICROGRIDDATUM_H
#define RESEARCH_MICROGRID_CPP_BOOLEANMICROGRIDDATUM_H

#include "MicrogridBooleanMeasurementType.h"

/**
 * BooleanMicrogridDatum
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
 * Important: the _id field of a Datum should be unique to the combination of its type and measurement location
 *  as a result, data from the same measurement location and type will have the same _id but different
 *  timestamp and value; this is important for data caching in LiveMicrogrid
 *
 * A unique identifier for an individual datum object should contain its _id AND its timestamp
 *
 *  @author Jake Billings
 */
class BooleanMicrogridDatum {
private:
    /**
     * measurementType
     *
     * MicrogridBooleanMeasurementType
     *
     * see the MicrogridBooleanMeasurementType docs
     *
     * this is the type of measurement made (e.g. Fault, CircuitBreakerStatus)
     */
    MicrogridBooleanMeasurementType measurementType;

    /**
     * value
     *
     * float
     *
     * the actual float reading represented by this datum object
     */
    bool value;

protected:
    //----Setters----
    //Setters are protected because this class is "immutable" (except for when deserializing)
    void setMeasurementType(MicrogridBooleanMeasurementType measurementType) {
        BooleanMicrogridDatum::measurementType = measurementType;
    }

    void setValue(bool value) {
        BooleanMicrogridDatum::value = value;
    }

public:
    /**
     * BooleanMicrogridDatum
     *
     * constructor: empty
     *
     * for use with deserialization; do not use for instantiation
     */
    BooleanMicrogridDatum() {}

    /**
     * BooleanMicrogridDatum()
     *
     * constructor
     *
     * @param timestamp the unix timestamp this datum was recorded at
     * @param node the node object this datum was recorded at
     * @param measurementType the boolean measurement type of this datum
     * @param value the boolean value of this measurement
     */
    BooleanMicrogridDatum(const MicrogridBooleanMeasurementType &measurementType, bool value) : measurementType(
            measurementType), value(value) {}

    MicrogridBooleanMeasurementType getMeasurementType() const {
        return measurementType;
    }

    bool isValue() const {
        return value;
    }
};


#endif //RESEARCH_MICROGRID_CPP_BOOLEANMICROGRIDDATUM_H
