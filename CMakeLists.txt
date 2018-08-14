cmake_minimum_required(VERSION 2.8.11)

#specify c++ version - 14 or 17 ?

project(RPG_ITEMS_CREATOR)

include(${PROJECT_SOURCE_DIR}/cmake/rpgItemsCreator/CMakeLists.txt)
include(${PROJECT_SOURCE_DIR}/cmake/test/CMakeLists.txt)

add_subdirectory(src/rpgItemsCreator rpgItemsCreator)
add_subdirectory(src/test test)

enable_testing()
add_test(NAME MyTest COMMAND Test)

set(INCLUDE_DIR src/rpgItemsCreator)

set(INCL_DIRS
	INCLUDE_DIR
	thirdparty/json/include)

target_include_directories(ObjectLib PUBLIC thirdparty/json/include)
target_include_directories(rpgItemsCreator PRIVATE ${INCL_DIRS})
target_include_directories(Test PRIVATE ${INCL_DIRS})