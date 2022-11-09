#include "module_manager.h"

#include "../utility/board_manager.h"
#include "badge_module.h"
#include "impl/hello_nametag.h"

namespace badge {
    module_manager_t::module_manager_t() {
        //instantiate modules
        _root_module = new hello_nametag_t();
        _current_module = _root_module;
    }

    module_manager_t::~module_manager_t() {

    }

    void module_manager_t::handle_button(pressed_button &button) {
        _last_pressed_button = button;
        
        switch (button) {
            case pressed_button::UP:
                _current_module->move_selection(_dir_up);
                break;
            case pressed_button::DOWN:
                _current_module->move_selection(_dir_down);
                break;
        }
    }
    
    // badge_module_t* module_manager_t::getCurrentModule() const{
    //     return _current_module;
    // }
    int module_manager_t::print_screen(screen_printer_t &printer) {
     //   if (_current_module->is_unclean()) {
            return _current_module->print_screen(printer);
       // }

        return 0;
    }
}