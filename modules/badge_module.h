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

            //todo change this int to uint8_t (or bool)
            virtual int print_screen(screen_printer_t &printer) = 0;
            virtual void move_selection(int8_t &direction) = 0;
            virtual void activate_one() = 0;
            virtual void activate_two() = 0; //activate_two should only be callable when selected_child is nullptr

            bool is_unclean();
            void set_unclean();

            badge_module_t* parent = nullptr;
            badge_module_t* selected_child = nullptr;

        protected:
            bool _initialized = false;
            bool _clean_state = false;
    };
}

#endif
