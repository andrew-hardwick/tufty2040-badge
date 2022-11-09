#ifndef BADGE_MODULE_H
#define BADGE_MODULE_H

#include <string>

#include <pico/stdlib.h>

#include "../display/screen_printer.h"

namespace badge {
    class badge_module_t {
        public:
            badge_module_t() {}
            ~badge_module_t() {}
            virtual int print_screen(screen_printer_t &printer) = 0;
            virtual void move_selection(int8_t &direction) = 0;
            virtual void select(badge_module_t &result) = 0;

            bool is_unclean();

        protected:
            bool _clean_state = false;
    };
}

#endif
