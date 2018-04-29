cmake_minimum_required(VERSION 3.9)
project(research_microgrid_cpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(research_microgrid_cpp main.cpp src/data/abs/Node.cpp src/data/abs/Node.h src/data/abs/Entity.cpp src/data/abs/Entity.h src/data/abs/Datum.cpp src/data/abs/Datum.h src/data/MicrogridDatum.cpp src/data/MicrogridDatum.h src/data/MicrogridNode.cpp src/data/MicrogridNode.h src/data/MicrogridNodeType.h src/data/FloatMicrogridDatum.cpp src/data/FloatMicrogridDatum.h src/data/MicrogridFloatMeasurementType.h src/data/MicrogridBooleanMeasurementType.h src/data/BooleanMicrogridDatum.cpp src/data/BooleanMicrogridDatum.h src/compat/Externalizable.cpp src/compat/Externalizable.h test/test.cpp test/test_support.cpp test/test_support.h test/test.h src/compat/utf.cpp src/compat/utf.h src/compat/endian.cpp src/compat/endian.h)