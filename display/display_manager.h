#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <cstdlib>
#include <string>

#include <pico/stdlib.h>
#include <tufty2040.hpp>
#include <drivers/st7789/st7789.hpp>
#include <libraries/pico_graphics/pico_graphics.hpp>

#include "../utility/board_manager.h"
#include "../modules/module_manager.h"
#include "screen_printer.h"

namespace badge {
    class display_manager_t {
        public:
            display_manager_t();
            ~display_manager_t();

            void update(module_manager_t &module_manager);
            void update(board_manager_t & board_manager);

            void display_large_text(std::string text, pimoroni::Point text_location, uint16_t wrap);

            void debug();
            
        private:
            pimoroni::ST7789 screen_interface;
            pimoroni::PicoGraphics_PenRGB332 graphics;

            screen_printer_t screen_printer;

            uint8_t backlight_options [6] = {25, 50, 100, 150, 200, 250};
            uint8_t backlight_options_length = 6;
            uint8_t current_backlight_setting = 3;
    };
}

// ST7789 st7789(PicoDisplay::WIDTH, PicoDisplay::HEIGHT, ROTATE_0, false, get_spi_pins(BG_SPI_FRONT));
// PicoGraphics_PenRGB332 graphics(st7789.width, st7789.height, nullptr);

// uint8_t backlight_options [6] = {25, 50, 100, 150, 200, 250};
// uint8_t backlight_options_length = 6;
// uint8_t current_backlight_setting = 3;


#endif