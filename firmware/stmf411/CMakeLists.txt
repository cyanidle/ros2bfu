add_subdirectory(cmake/stm32cubemx)

target_sources(ros2bfu PRIVATE
    libmicroros/extra_sources/custom_memory_manager.c
    libmicroros/extra_sources/microros_allocators.c
    libmicroros/extra_sources/microros_time.c

    libmicroros/extra_sources/microros_transports/usb_cdc_transport.c
)

target_include_directories(ros2bfu PRIVATE
    libmicroros/microros_include
)

target_link_libraries(ros2bfu
    stm32cubemx

    ${CMAKE_CURRENT_SOURCE_DIR}/libmicroros/libmicroros.a
)