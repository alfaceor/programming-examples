
cmake_minimum_required(VERSION 2.8)
 
PROJECT(ReadTextFile)
 
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
 
add_executable(ReadTextFile MACOSX_BUNDLE ReadTextFile.cxx )
 
target_link_libraries(ReadTextFile ${VTK_LIBRARIES})
