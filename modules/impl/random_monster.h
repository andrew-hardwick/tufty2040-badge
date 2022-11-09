#ifndef RANDOM_MONSTER_H
#define RANDOM_MONSTER_H

#include <pico/stdlib.h>

#include "../../display/screen_printer.h"

#include "../badge_module.h"

namespace badge {
    class random_monster_t : public badge_module_t {
        public:
            random_monster_t();
            ~random_monster_t();

            int print_screen(screen_printer_t &printer);
            void move_selection(int8_t &direction);
            void activate_one();
            void activate_two();
        
        private:
            uint8_t _selected_floor = 0;
            uint16_t _selected_monster = 0;
    };
}

#endif