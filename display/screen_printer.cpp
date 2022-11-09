#include "screen_printer.h"

#include <string>

#include <pico/stdlib.h>
#include <drivers/st7789/st7789.hpp>

namespace badge {
    screen_printer_t::screen_printer_t(pimoroni::PicoGraphics_PenRGB332* graphics) :
        _existing_pens()
    {
        _graphics = graphics;
    }

    screen_printer_t::~screen_printer_t() {

    }
    
    void screen_printer_t::create_pen(std::string pen_name, uint8_t r, uint8_t g, uint8_t b) {
        if (_existing_pens.count(pen_name) == 1) {
            //todo update pen color **CAREFUL OF MEMORY**
        }
        else {
            _existing_pens.insert({pen_name, _graphics->create_pen(r, g, b)});
        }
    }

    void screen_printer_t::clear_screen(std::string pen_name) {
        if (_existing_pens.count(pen_name) == 1) {
            _graphics->set_pen(_existing_pens.find(pen_name)->second);
            _graphics->clear();
        }
    }
    
    void screen_printer_t::draw_rect(std::string pen_name, int32_t x, int32_t y, int32_t w, int32_t h) {
        if (_existing_pens.count(pen_name) == 1) {
            _graphics->set_pen(_existing_pens.find(pen_name)->second);
            pimoroni::Rect rect(0, 80, 320, 120);
            _graphics->rectangle(rect);
        }
    }

    void screen_printer_t::draw_text(std::string pen_name, std::string font, std::string text, pimoroni::Point location, float size, uint8_t repl) {
        if (_existing_pens.count(pen_name) == 1) {
            _graphics->set_pen(_existing_pens.find(pen_name)->second);
            _graphics->set_font(font);

            for (uint8_t i; i < repl; i++) {
                for (uint8_t j; j < repl; j++) {
                    _graphics->text(text, location, 320, size);
                    location.x += 1;
                }
                location.y += 2;
            }
        }
    }
}