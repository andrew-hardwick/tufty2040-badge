#ifndef SCREEN_PRINTER_H
#define SCREEN_PRINTER_H

#include <map>
#include <string>

#include <pico/stdlib.h>
#include <drivers/st7789/st7789.hpp>

namespace badge {
    class screen_printer_t {
        public:
            screen_printer_t(pimoroni::PicoGraphics_PenRGB332* graphics);
           ~screen_printer_t();

            void create_pen(std::string pen_name, uint8_t r, uint8_t g, uint8_t b);

            void clear_screen(std::string pen_name);
            void draw_rect(std::string pen_name, int32_t x, int32_t y, int32_t w, int32_t h);
            void draw_text(std::string pen_name, std::string font, std::string text, pimoroni::Point location, float size, uint8_t repl);
        
        private:
            pimoroni::PicoGraphics_PenRGB332* _graphics;
            std::map<std::string, pimoroni::Pen> _existing_pens;

    };
}

#endif