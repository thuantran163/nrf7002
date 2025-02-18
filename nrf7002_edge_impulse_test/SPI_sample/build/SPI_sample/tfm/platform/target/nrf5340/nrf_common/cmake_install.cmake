# Install script for directory: /workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/root/ncs/toolchains/b77d8c1312/opt/zephyr-sdk/arm-zephyr-eabi/bin/arm-zephyr-eabi-objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/interface/include/tfm_ioctl_core_api.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/interface/include" TYPE FILE MESSAGE_LAZY FILES "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/services/include/tfm_ioctl_core_api.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/interface/src/tfm_ioctl_core_ns_api.c")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/interface/src" TYPE FILE MESSAGE_LAZY FILES "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/services/src/tfm_ioctl_core_ns_api.c")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/config_nordic_nrf_spe.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core" TYPE FILE MESSAGE_LAZY FILES "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/config_nordic_nrf_spe.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/ext/driver/Driver_Common.h;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/ext/driver/Driver_Flash.h;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/ext/driver/Driver_USART.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/ext/driver" TYPE FILE MESSAGE_LAZY FILES
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/driver/Driver_Common.h"
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/driver/Driver_Flash.h"
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/driver/Driver_USART.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/startup.c;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/startup_nrf5340.c;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/nrfx_glue.c;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/pal_plat_test.c;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/pal_plat_test.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core" TYPE FILE MESSAGE_LAZY FILES
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/startup.c"
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/startup_nrf5340.c"
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/nrfx_glue.c"
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/pal_plat_test.c"
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/pal_plat_test.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/startup.h;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/target_cfg.h;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/nrfx_config.h;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/CMakeLists.txt;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/config.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core" TYPE FILE MESSAGE_LAZY FILES
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/startup.h"
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/target_cfg.h"
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/nrfx_config.h"
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/ns/CMakeLists.txt"
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/config.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/native_drivers;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/cmsis_drivers;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/common;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/nrfx;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/services;/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core/tests")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/common/core" TYPE DIRECTORY MESSAGE_LAZY FILES
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/native_drivers"
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/cmsis_drivers"
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/common"
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/nrfx"
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/services"
    "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/target/nordic_nrf/common/core/tests"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/linker_scripts/tfm_common_ns.ld")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/workspace/01.Emotiv/nrf7002/nrf7002_edge_impulse_test/SPI_sample/build/SPI_sample/tfm/api_ns/platform/linker_scripts" TYPE FILE MESSAGE_LAZY FILES "/workspace/.emotiv/nrfconnect/v2.9.0-nRF54H20-rc1/modules/tee/tf-m/trusted-firmware-m/platform/ext/common/gcc/tfm_common_ns.ld")
endif()

