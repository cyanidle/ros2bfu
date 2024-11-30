cmake_minimum_required(VERSION 3.22)

set(STM stmf103 CACHE STRING "Variant of stm to use")
set_property(CACHE STM PROPERTY STRINGS "stmf103" "stmf411")

message(STATUS "Using STM: ${STM}")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()
message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})

include(${STM}/cmake/gcc-arm-none-eabi.cmake)


set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(ros2bfu C ASM CXX)

add_executable(ros2bfu)

add_subdirectory(${STM})

target_sources(ros2bfu PRIVATE 
    ./bfu/bfumain.cpp
)

add_custom_command(TARGET ros2bfu POST_BUILD
    COMMENT "Generating ros2bfu.hex"
    COMMAND ${CMAKE_OBJCOPY} ARGS -O ihex $<TARGET_FILE:ros2bfu> ros2bfu.hex
)
