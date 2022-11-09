#ifndef MODULE_SELECT_H
#define MODULE_SELECT_H

#include "../badge_module.h"

namespace badge {
    class module_select_t : public badge_module_t {
        public:
            module_select_t();
            ~module_select_t();
        
            int print_screen(screen_printer_t &printer) = 0;
            void move_selection(int8_t &direction) = 0;
            void select(badge_module_t &result) = 0;
    }
}

#endif
