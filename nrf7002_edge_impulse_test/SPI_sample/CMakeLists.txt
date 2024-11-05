#
# Copyright (c) 2024 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(nrf_connect_sdk_intermediate)
target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/LIS302DL_driver/inc)


set ( SOURCES
      src/main.c
      LIS302DL_driver/src/Accelero_instance.c
      LIS302DL_driver/src/LIS302DL.c
 
)
target_sources(app PRIVATE ${SOURCES})
