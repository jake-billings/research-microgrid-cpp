/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */
#include "test.h"

#include <sstream>

#include "../src/compat/utf.h"
#include "../src/data/MicrogridNode.h"
#include "../src/data/FloatMicrogridDatum.h"

/**
 * int test()
 *
 * Tests the functionality of the union operators; logs errors to the console if they exist
 */
void test() {
    //Keep track of how many tests we fail
    unsigned int failCount = 0;

    //Print welcome message
    cout << "========Unit Tests========" << endl;

    describe("endian: swap64: should be inverse of itself for 0");
    failCount += assertLong(0, swap64(swap64(0)));
    describe("endian: swap64: should be inverse of itself for 999");
    failCount += assertLong(999, swap64(swap64((999))));
    describe("endian: swap64: should be inverse of itself for 1000");
    failCount += assertLong(1000, swap64(swap64(1000)));
    describe("endian: swap64: should be inverse of itself for 1524957684755");
    failCount += assertLong(1524957684755, swap64(swap64(1524957684755)));

    describe("endian: swap32: should be inverse of itself for 0");
    failCount += assertLong(0, swap32(swap32(0)));
    describe("endian: swap32: should be inverse of itself for 999");
    failCount += assertLong(999, swap32(swap32((999))));
    describe("endian: swap32: should be inverse of itself for 1000");
    failCount += assertLong(1000, swap32(swap32(1000)));

    describe("utf: should encode/decode a test string to/from utf8");
    string testString = "this is a simple test string";
    std::ostringstream testOutputBuffer;
    writeUTF(testString, testOutputBuffer);
    std::istringstream testInputBuffer(testOutputBuffer.str());
    string result = readUTF(testInputBuffer);
    failCount += assertString(testString, result);


    //----Should Serialize and Deserialize a FloatMicrogridDatumMessage----
    //Dummy time from when I wrote this code
//    long now = 999;
    long now = 1524957684755;
    float value = 3;

    MicrogridNode g("microgrid-node-a-g", MicrogridNodeType::GENERATOR);

    FloatMicrogridDatum datum(now, &g, MicrogridFloatMeasurementType::VOLTAGE, value);

    describe("FloatMicrogridDatum: should store timestamp");
    failCount += assertLong(now, datum.getTimestamp());
    describe("FloatMicrogridDatum: should store node");
    failCount += assertString(g.get_id(), datum.getNode()->get_id());
    describe("FloatMicrogridDatum: should store measurement type");
    failCount += assertInt(MicrogridFloatMeasurementType::VOLTAGE, datum.getMeasurementType());
    describe("FloatMicrogridDatum: should store value");
    failCount += assertFloat(value, datum.getValue());
    describe("FloatMicrogridDatum: should generate _id value");
    failCount += assertString("microgrid-node-a-g-1", datum.get_id());

    std::ostringstream s;
    datum.writeExternal(s);
    cout << s.str();
    std::cout << endl;

    FloatMicrogridDatum datum2;
    std::istringstream is(s.str());
    datum2.readExternal(is);

    describe("FloatMicrogridDatum: should store timestamp");
    failCount += assertLong(now, datum2.getTimestamp());
    describe("FloatMicrogridDatum: should store node");
    failCount += assertString(g.get_id(), datum2.getNode()->get_id());
    describe("FloatMicrogridDatum: should store measurement type");
    failCount += assertInt(MicrogridFloatMeasurementType::VOLTAGE, datum2.getMeasurementType());
    describe("FloatMicrogridDatum: should store value");
    failCount += assertFloat(value, datum2.getValue());
    describe("FloatMicrogridDatum: should generate _id value");
    failCount += assertString("microgrid-node-a-g-1", datum2.get_id());

    //Completion message
    cout << endl << "Completed automated tests. Failed " << failCount << " tests." << endl;
    cout << "======End Unit Tests======" << endl;

}