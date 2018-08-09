add_library(ObjectLib object/ObjectBuilder.cpp object/ObjectBuilder.hpp)

add_executable(rpgItemsCreator main.cpp)
target_link_libraries(rpgItemsCreator ObjectLib)