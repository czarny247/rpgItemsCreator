#add_library(ObjectLib object/ObjectBuilder.cpp object/ObjectBuilder.hpp)
add_library(ObjectLib object/ObjectBuilder.cpp)

target_include_directories(ObjectLib PUBLIC
	${PROJECT_SOURCE_DIR}/src/object)

add_executable(rpgItemsCreator main.cpp)
target_link_libraries(rpgItemsCreator ObjectLib)