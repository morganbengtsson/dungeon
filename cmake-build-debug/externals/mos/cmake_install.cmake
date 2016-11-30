# Install script for directory: /home/morgan/Projects/Dungeon on the fly/externals/mos

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/morgan/Projects/Dungeon on the fly/cmake-build-debug/externals/mos/externals/glew-cmake/cmake_install.cmake")
  include("/home/morgan/Projects/Dungeon on the fly/cmake-build-debug/externals/mos/externals/glfw/cmake_install.cmake")
  include("/home/morgan/Projects/Dungeon on the fly/cmake-build-debug/externals/mos/externals/openal-soft/cmake_install.cmake")
  include("/home/morgan/Projects/Dungeon on the fly/cmake-build-debug/externals/mos/externals/Optional/cmake_install.cmake")
  include("/home/morgan/Projects/Dungeon on the fly/cmake-build-debug/externals/mos/externals/glm/cmake_install.cmake")
  include("/home/morgan/Projects/Dungeon on the fly/cmake-build-debug/externals/mos/externals/lodepng/cmake_install.cmake")
  include("/home/morgan/Projects/Dungeon on the fly/cmake-build-debug/externals/mos/externals/stb/cmake_install.cmake")
  include("/home/morgan/Projects/Dungeon on the fly/cmake-build-debug/externals/mos/externals/json/cmake_install.cmake")

endif()

