cmake_minimum_required(VERSION 2.8.11)

project(rpgItemsCreator)

#creating test executable
#todo - this step only in debug / not in release
include(cmake/test/CMakeLists.txt)

add_executable(rpgItemsCreator src/rpgItemsCreator/main.cpp)