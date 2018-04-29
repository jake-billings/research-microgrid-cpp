//
// Created by Jake Billings on 4/28/18.
//

#include "FloatMicrogridDatum.h"


FloatMicrogridDatum::FloatMicrogridDatum(long timestamp, const MicrogridNode *node,
                                         MicrogridFloatMeasurementType measurementType, float value) : MicrogridDatum(
        timestamp, node, measurementType), measurementType(measurementType), value(value) {

}

MicrogridFloatMeasurementType FloatMicrogridDatum::getMeasurementType() const {
    return measurementType;
}

void FloatMicrogridDatum::setMeasurementType(MicrogridFloatMeasurementType measurementType) {
    FloatMicrogridDatum::measurementType = measurementType;
}

float FloatMicrogridDatum::getValue() const {
    return value;
}

void FloatMicrogridDatum::setValue(float value) {
    FloatMicrogridDatum::value = value;
}

void FloatMicrogridDatum::writeExternal(std::ostream &out) const {
    MicrogridDatum::writeExternal(out);
    float reversed = ReverseFloat(this->getValue());
    out.write(reinterpret_cast<const char*>(&reversed), sizeof(float));
    out.write(reinterpret_cast<const char*>(&this->measurementType), sizeof(MicrogridFloatMeasurementType));
}

void FloatMicrogridDatum::readExternal(std::istream &in) {
    MicrogridDatum::readExternal(in);
    float reversed;
    in.read(reinterpret_cast<char*>(&reversed), sizeof(float));
    this->setValue(ReverseFloat(reversed));
    in.read(reinterpret_cast<char*>(&this->measurementType), sizeof(MicrogridFloatMeasurementType));
}
