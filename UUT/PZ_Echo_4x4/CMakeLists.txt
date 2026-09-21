
file(GLOB common_SRC CONFIGURE_DEPENDS
        "../../Common/*.cpp"
        "../../lib/tusb_ump/*.cpp"
        "../../lib/AM_MIDI2.0Lib/src/*.cpp"
        )

add_executable(UUT_PZ_ECHO_4X4
        main.cpp
        usb_descriptors.cpp
        ${common_SRC}
        )

# Make sure TinyUSB can find tusb_config.h
target_include_directories(UUT_PZ_ECHO_4X4 PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        .
        ../../Common
        ../../Common/include
        ../../lib/tusb_ump
        ../../lib/AM_MIDI2.0Lib
        )

#Temporary suppression of compile waring for MIDI2_CPP
target_compile_options(UUT_PZ_ECHO_4X4 PRIVATE -Wno-narrowing -Wno-unused-variable)

# pull in common dependencies
target_link_libraries(UUT_PZ_ECHO_4X4
        pico_stdlib
        pico_stdio
        pico_unique_id
        tinyusb_device
        hardware_pio
        hardware_adc
        hardware_spi
        hardware_flash
        hardware_dma
        libmidi2
)

# create map/bin/hex file etc.
pico_add_extra_outputs(UUT_PZ_ECHO_4X4)
