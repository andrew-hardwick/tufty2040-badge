#ifndef BADGE_MODULE_H
#define BADGE_MODULE_H

#include <string>

#include "../display/screen_printer.h"

namespace badge {
    class badge_module_t {
        public:
            badge_module_t();
            virtual ~badge_module_t();
            virtual void print_screen(screen_printer_t printer) = 0;
            virtual void move_selection(int8_t direction) = 0;
            virtual void select(badge_module_t &result) = 0;
    };
}

#endif
