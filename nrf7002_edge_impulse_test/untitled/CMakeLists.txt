cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

project(untitled)
set ( SOURCES
      src/main.c
 
)
target_sources(app PRIVATE ${SOURCES})

 