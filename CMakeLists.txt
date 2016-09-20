project(Dungeon)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
IF(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
ENDIF(CMAKE_COMPILER_IS_GNUCC)

add_definitions(-DDEBUG)
add_definitions(-DGLM_FORCE_RADIANS)
add_definitions(-DGLEW_STATIC)

include_directories(externals/mos/externals/glm)

#Copy assets to build dir
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# mos
add_subdirectory(externals/mos)
include_directories(externals/mos/include)

# Main
file(GLOB SRC "src/*.cpp")
file(GLOB INCLUDE "include/*.hpp")
file(GLOB TXT "*.txt")
include_directories(include)
add_executable(${PROJECT_NAME} ${INCLUDE} ${SRC} ${TXT})

# Link
#target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES})
if (UNIX)
    target_link_libraries(${PROJECT_NAME} "Xcursor" "Xinerama" "tbb") #Theese should be included in glfw?
endif()
target_link_libraries(${PROJECT_NAME} mos)
