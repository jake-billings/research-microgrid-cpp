/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */
#ifndef RESEARCH_MICROGRID_CPP_MICROGRIDBOOLEANMEASUREMENTTYPE_H
#define RESEARCH_MICROGRID_CPP_MICROGRIDBOOLEANMEASUREMENTTYPE_H

/**
 * MicrogridBooleanMeasurementType
 *
 * enum
 *
 * types of measurements MicrogridBooleamDatum can have and unit strings for them
 *
 * E.g. Voltage-Volts-V
 *
 * @author Jake Billings
 */
enum MicrogridBooleanMeasurementType : char {
    FAULT = -1,
    WARNING = -2,
    CIRCUIT_BREAKER_TRIPPED = -3
};

#endif //RESEARCH_MICROGRID_CPP_MICROGRIDBOOLEANMEASUREMENTTYPE_H
