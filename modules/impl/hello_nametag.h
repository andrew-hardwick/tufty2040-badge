#ifndef HELLO_NAMETAG_H
#define HELLO_NAMETAG_H

#include <string>
#include <vector>

#include <pico/stdlib.h>

#include "../badge_module.h"
#include "../../display/screen_printer.h"

namespace badge {
    class hello_nametag_t : public badge_module_t {
        public:
            hello_nametag_t();
            ~hello_nametag_t();

            int print_screen(screen_printer_t &printer);
            void move_selection(int8_t &direction);
            void select(badge_module_t &result);
            void clear(badge_module_t &result);
        
        private:
            bool _initialized = false;
            int8_t _color_index = 0;
            //vector strings for colors
            std::vector<std::string> _backgrounds;
            std::vector<std::string> _foregrounds;
    };
}

#endif