#include "display_manager.h"

#include <cstdlib>
#include <string>

#include <pico/stdlib.h>
#include <common/pimoroni_common.hpp>
#include <tufty2040.hpp>
#include <drivers/st7789/st7789.hpp>
#include <libraries/pico_graphics/pico_graphics.hpp>

#include "../utility/board_manager.h"
#include "../modules/module_manager.h"

namespace badge {
    display_manager_t::display_manager_t() :
        screen_interface(
            pimoroni::Tufty2040::WIDTH,
            pimoroni::Tufty2040::HEIGHT,
            pimoroni::ROTATE_180, 
            pimoroni::ParallelPins{
                pimoroni::Tufty2040::LCD_CS,
                pimoroni::Tufty2040::LCD_DC,
                pimoroni::Tufty2040::LCD_WR,
                pimoroni::Tufty2040::LCD_RD,
                pimoroni::Tufty2040::LCD_D0, 
                pimoroni::Tufty2040::BACKLIGHT
            }
        ),
        graphics(screen_interface.width, screen_interface.height, nullptr),
        screen_printer(&graphics)
    {
        screen_interface.set_backlight(255);
        
        screen_printer.create_pen("error_bg", 0, 0, 0);
        screen_printer.create_pen("error_text", 255, 0, 0);
        screen_printer.create_pen("debug_bg", 20, 0, 20);
        screen_printer.create_pen("debug_text", 0, 255, 0);

    }

    display_manager_t::~display_manager_t() {

    }

    void display_manager_t::update_board(board_manager_t &board_manager) {
        uint16_t brightness = board_manager.get_lux();

        if (brightness < 95) brightness = 95;
        brightness <<= 1;

        if (brightness > 255) brightness = 255;

        screen_interface.set_backlight((uint8_t) brightness);
    }

    void display_manager_t::update_module(module_manager_t &module_manager) {
        if (module_manager.print_screen(screen_printer) != 0) {
            //draw error message
            error();
        }

        //update the screen
        screen_interface.update(&graphics);
    }

    void display_manager_t::error() {
        screen_printer.clear_screen("error_bg");

        pimoroni::Point text_location(0, 120);
        screen_printer.draw_text("error_text", "sans_bold", "ERROR", text_location, 3, 8);
    }

    void display_manager_t::debug() { 
        screen_printer.clear_screen("debug_bg");

        pimoroni::Point text_location(0, 0);
        screen_printer.draw_text("debug_text", "bitmap8", "DEBUG", text_location, 1, 1);
        screen_interface.update(&graphics);
    }
}