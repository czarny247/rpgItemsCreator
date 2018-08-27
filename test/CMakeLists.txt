set(TEST_SOURCES object/ObjectBuilderTests.cpp)

add_executable(Test ${PROJECT_SOURCE_DIR}/test/main.cpp)

target_sources(Test PRIVATE ${TEST_SOURCES})
target_link_libraries(Test ObjectLib gtest_main)