cmake_minimum_required(VERSION 3.12)

# Change your executable name to something creative!
set(NAME ips_badge) # <-- Name your project/executable here!

include(pimoroni_pico_import.cmake)
include(pico_sdk_import.cmake)

# Gooey boilerplate
project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Add your source files
add_executable(${NAME}
    main.cpp
    display/display_manager.cpp
    display/screen_printer.cpp
    modules/module_manager.cpp
    modules/badge_module.cpp
    modules/impl/hello_nametag.cpp
    utility/board_manager.cpp
    utility/rand_utils.cpp
)

# Include required libraries
# This assumes `pimoroni-pico` is stored alongside your project
include(libraries/bitmap_fonts/bitmap_fonts)
include(libraries/hershey_fonts/hershey_fonts)
include(libraries/tufty2040/tufty2040)
include(libraries/pico_graphics/pico_graphics)
include(common/pimoroni_bus)
include(drivers/st7789/st7789)
include(drivers/rgbled/rgbled)
include(drivers/button/button)

# Don't forget to link the libraries you need!
target_link_libraries(${NAME}
    hardware_adc
    pico_stdlib
    hardware_spi
    rgbled
    tufty2040
    pico_graphics
    st7789
    button
)

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

# Set up files for the release packages
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${NAME}.uf2
    ${CMAKE_CURRENT_LIST_DIR}/README.md
    DESTINATION .
)

set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_GENERATOR "ZIP" "TGZ")
include(CPack)
