/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */

#ifndef RESEARCH_MICROGRID_CPP_MICROGRIDFLOATMEASUREMENTTYPE_H
#define RESEARCH_MICROGRID_CPP_MICROGRIDFLOATMEASUREMENTTYPE_H

/**
 * MicrogridFloatMeasurementType
 *
 * enum
 *
 * types of measurements MicrogridFloatDatum can have and unit strings for them
 *
 * E.g. Voltage-Volts-V
 *
 * @author Jake Billings
 */
enum MicrogridFloatMeasurementType: char {
    VOLTAGE=1,
    AMPERAGE=2,
    WATTAGE=3
};

#endif //RESEARCH_MICROGRID_CPP_MICROGRIDFLOATMEASUREMENTTYPE_H
