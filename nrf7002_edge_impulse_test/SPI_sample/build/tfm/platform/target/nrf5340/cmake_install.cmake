# Install script for directory: /root/ncs/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/nrf5340

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns")
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
  set(CMAKE_OBJDUMP "/root/zephyr-sdk-0.17.0/arm-zephyr-eabi/bin/arm-zephyr-eabi-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/platform/target/nrf5340/nrf_common/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform/common/nrf5340/nrfx_config_nrf5340_application.h;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform/common/nrf5340/CMakeLists.txt;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform/common/nrf5340/config.cmake;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform/common/nrf5340/cpuarch.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform/common/nrf5340" TYPE FILE MESSAGE_NEVER FILES
    "/root/ncs/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/nrf5340/nrfx_config_nrf5340_application.h"
    "/root/ncs/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/nrf5340/ns/CMakeLists.txt"
    "/root/ncs/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/nrf5340/config.cmake"
    "/root/ncs/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/nrf5340/cpuarch.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform/common/nrf5340/partition;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform/common/nrf5340/tests")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/tfm/api_ns/platform/common/nrf5340" TYPE DIRECTORY MESSAGE_NEVER FILES
    "/root/ncs/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/nrf5340/partition"
    "/root/ncs/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/nrf5340/tests"
    )
endif()

