#ifndef MODULE_SELECT_H
#define MODULE_SELECT_H

#include <vector>
#include <string>

#include "../badge_module.h"

namespace badge {
    class module_select_t : public badge_module_t {
        public:
            module_select_t();
            ~module_select_t();
        
            int print_screen(screen_printer_t &printer);
            void move_selection(int8_t &direction);
            void activate_one();
            void activate_two();
        
        private:
            std::vector<badge_module_t*> _children;
            std::vector<std::string> _children_names;

            int8_t _selected_index = 0;
    };
}

#endif
