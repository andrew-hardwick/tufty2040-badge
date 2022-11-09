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
#include "badge_fonts.h"

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
    }

    display_manager_t::~display_manager_t() {

    }

    void display_manager_t::update(board_manager_t &board_manager) {
        uint16_t brightness = board_manager.get_lux();

        if (brightness < 95) brightness = 95;
        brightness <<= 1;

        if (brightness > 255) brightness = 255;

        screen_interface.set_backlight((uint8_t) brightness);
    }

    void display_manager_t::update(module_manager_t &module_manager) {
        auto module = module_manager.getCurrentModule();

        //draw the base screen
        //possibly query the current module

        //draw options or ui
        //must query the current module

        //update the screen
        screen_interface.update(&graphics);
    }

    void display_manager_t::debug() { 
        screen_printer.create_pen("white", 255, 255, 255);
        screen_printer.create_pen("bg", 10, 10, 100);
        screen_printer.create_pen("black", 0, 0, 0);

        pimoroni::Point text_location(0, 32);

    //Red Background
        screen_printer.clear_screen("bg");

    //White Rectangle
        screen_printer.draw_rect("white", 0, 80, 320, 120);
    
    //HELLO
        text_location.x = 85;
        text_location.y = 25;
        screen_printer.draw_text("white", "sans_bold", "HELLO", text_location, 1.5, 1);
        
    //My Name Is
        text_location.y += 32;
        screen_printer.draw_text("white", "sans", "My Name Is:", text_location, .75, 1);

    //He/Him (bottom)
        text_location.x = 110;
        text_location.y = 220;
        screen_printer.draw_text("white", "sans", "He/Him", text_location, .75, 1);

    //Drew (name)
        text_location.x = 25;
        text_location.y = 140;
        screen_printer.draw_text("black", "sans_bold", "Drew", text_location, 3.5, 8);

        screen_interface.update(&graphics);
    }

    void display_manager_t::display_large_text(std::string text, pimoroni::Point text_location, uint16_t wrap) {
        uint16_t length = text.length();

        //testing
        length = 1;

        for(uint16_t i = 0; i < length; i++) {
            char test = text[i];
            graphics.text(std::to_string(test), text_location, wrap);
            text_location.y += 16;
        }
    }
}