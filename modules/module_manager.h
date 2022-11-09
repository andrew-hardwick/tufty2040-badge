#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include "../display/screen_printer.h"
#include "../utility/board_manager.h"
#include "badge_module.h"

namespace badge {
    class module_manager_t {
        public:
            module_manager_t();
            ~module_manager_t();

            void handle_button(pressed_button &button);
            int print_screen(screen_printer_t &screen_printer);
        
        private:
            pressed_button _last_pressed_button;
            
            badge_module_t* _root_module;
            badge_module_t* _current_module;

            int8_t _dir_up = -1;
            int8_t _dir_down = 1;
    };
}

#endif