#include "module_manager.h"

#include "../utility/board_manager.h"
#include "badge_module.h"

namespace badge {
    module_manager_t::module_manager_t() {
        //instantiate modules
    }

    module_manager_t::~module_manager_t() {

    }

    void module_manager_t::handle_button(pressed_button button) {

    }

    bool module_manager_t::is_unclean() {
        return false;
    }
    
    badge_module_t* module_manager_t::getCurrentModule() const{
        return nullptr;
    }
}