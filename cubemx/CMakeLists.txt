cmake_minimum_required(VERSION 3.22)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_PROJECT_NAME ros2bfu)

include("cmake/gcc-arm-none-eabi.cmake")

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(ros2bfu LANGUAGES C ASM CXX)
message("Build type: " ${CMAKE_BUILD_TYPE})

# Create an executable object type
add_executable(ros2bfu)

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(ros2bfu PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(ros2bfu PRIVATE
    libmicroros/extra_sources/custom_memory_manager.c
    libmicroros/extra_sources/microros_allocators.c
    libmicroros/extra_sources/microros_time.c

    libmicroros/extra_sources/microros_transports/usb_cdc_transport.c

    bfu/bfumain.cpp
)

target_include_directories(ros2bfu PRIVATE
    libmicroros/microros_include
)

target_compile_definitions(ros2bfu PRIVATE

)

target_link_libraries(ros2bfu
    stm32cubemx

    ${CMAKE_SOURCE_DIR}/libmicroros/libmicroros.a
)

add_custom_command(TARGET ros2bfu POST_BUILD
    COMMENT "Generating ros2bfu.hex"
    COMMAND ${CMAKE_OBJCOPY} ARGS -O ihex $<TARGET_FILE:ros2bfu> ros2bfu.hex
)