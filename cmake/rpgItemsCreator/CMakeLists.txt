#add all external dependecies here
configure_file(${PROJECT_SOURCE_DIR}/cmake/rpgItemsCreator/json-CMakeLists.txt.in json-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/json-download)
if(result)
  message(FATAL_ERROR "CMake step for json failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/json-download)
if(result)
  message(FATAL_ERROR "Build step for json failed: ${result}")
endif()

file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/json-download)