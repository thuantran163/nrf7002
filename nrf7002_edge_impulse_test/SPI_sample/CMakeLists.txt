# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause

cmake_minimum_required(VERSION 3.20.0)

# Set C/C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Force C++ compiler usage for main.cpp
set_source_files_properties(src/main.cpp PROPERTIES LANGUAGE CXX)

# Enable verbose output for debugging
set(CMAKE_VERBOSE_MAKEFILE ON)

# Add custom flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSTATIC_INIT_GNU")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSTATIC_INIT_GNU -D_GLIBCXX_USE_CXX11_ABI=1")

# Find Zephyr and set up the project
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(nrf_connect_sdk_intermediate)
#set(PM_YML_FILE ${CMAKE_CURRENT_SOURCE_DIR}/pm.yml)
# Include directories
target_include_directories(app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/LIS302DL_driver/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Add libraries and subdirectories
add_subdirectory(lib)

# Define source files
set(SOURCES
    src/main.cpp
    LIS302DL_driver/src/Accelero_instance.c
    LIS302DL_driver/src/LIS302DL.c
)

# Add sources to the app target
target_sources(app PRIVATE ${SOURCES})

# Link C++ standard library explicitly
target_link_libraries(app PRIVATE stdc++)
