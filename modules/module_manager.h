#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include "../utility/board_manager.h"
#include "badge_module.h"

namespace badge {
    class module_manager_t {
        public:
            module_manager_t();
            ~module_manager_t();

            void handle_button(pressed_button button);
            bool is_unclean();
            badge_module_t* getCurrentModule() const;
    };
}

#endif