# Install script for directory: /home/thuantran/ncs/toolchains/nrf/modules/trusted-firmware-m/tfm_boards/nrf5340_cpuapp

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/thuantran/workspace/01.Projects/01.Embedded/06.EdgeImpulse/temp/nrf7002/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "MinSizeRel")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/home/thuantran/workspace/01.Projects/01.Embedded/03.NordicSemicon/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/thuantran/workspace/01.Projects/01.Embedded/06.EdgeImpulse/temp/nrf7002/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/platform/target/nrf5340/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/thuantran/workspace/01.Projects/01.Embedded/06.EdgeImpulse/temp/nrf7002/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/platform/target/tfm_board/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/thuantran/workspace/01.Projects/01.Embedded/06.EdgeImpulse/temp/nrf7002/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform/cpuarch.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/thuantran/workspace/01.Projects/01.Embedded/06.EdgeImpulse/temp/nrf7002/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform" TYPE FILE MESSAGE_NEVER RENAME "cpuarch.cmake" FILES "/home/thuantran/ncs/toolchains/nrf/modules/trusted-firmware-m/tfm_boards/nrf5340_cpuapp/ns/cpuarch_ns.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/thuantran/workspace/01.Projects/01.Embedded/06.EdgeImpulse/temp/nrf7002/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform/config.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/thuantran/workspace/01.Projects/01.Embedded/06.EdgeImpulse/temp/nrf7002/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform" TYPE FILE MESSAGE_NEVER FILES "/home/thuantran/ncs/toolchains/nrf/modules/trusted-firmware-m/tfm_boards/nrf5340_cpuapp/config.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/thuantran/workspace/01.Projects/01.Embedded/06.EdgeImpulse/temp/nrf7002/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform/../common/config.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/thuantran/workspace/01.Projects/01.Embedded/06.EdgeImpulse/temp/nrf7002/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform/../common" TYPE FILE MESSAGE_NEVER FILES "/home/thuantran/ncs/toolchains/nrf/modules/trusted-firmware-m/tfm_boards/nrf5340_cpuapp/../common/config.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/thuantran/workspace/01.Projects/01.Embedded/06.EdgeImpulse/temp/nrf7002/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform/tests")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/thuantran/workspace/01.Projects/01.Embedded/06.EdgeImpulse/temp/nrf7002/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform" TYPE DIRECTORY MESSAGE_NEVER FILES "/home/thuantran/ncs/toolchains/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/nrf5340dk_nrf5340_cpuapp/tests")
endif()

