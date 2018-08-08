include(${PROJECT_SOURCE_DIR}/cmake/test/CMakeLists.txt)

set(TEST_SOURCES object/ObjectBuilderTests.cpp)

add_executable(Test ${PROJECT_SOURCE_DIR}/src/test/main.cpp)

target_sources(Test PRIVATE ${TEST_SOURCES} ${SOURCES})
target_link_libraries(Test ObjectLib gtest_main)