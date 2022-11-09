#ifndef HELLO_NAMETAG_H
#define HELLO_NAMETAG_H

#include "../badge_module.h"

namespace badge : public badge_module_t {
    class hello_nametag_t {
        public:
            hello_nametag_t();
            ~hello_nametag_t();

            void print_screen(screen_printer_t printer);
            void move_selection(int8_t direction);
            void select(badge_module_t &result);
            void clear(badge_module_t &result);
    }
}

#endif