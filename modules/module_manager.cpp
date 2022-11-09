#include "module_manager.h"

#include "../utility/board_manager.h"
#include "badge_module.h"
#include "impl/module_select.h"

namespace badge {
    module_manager_t::module_manager_t() {
        //instantiate modules
        _root_module = new module_select_t();
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
            case pressed_button::B:
                _current_module->activate_one();
                break;
            case pressed_button::A:
                if (_current_module->parent) {
                    _current_module = _current_module->parent;
                    _current_module->set_unclean();
                }
                break;
            case pressed_button::C:
                if (_current_module->selected_child) {
                    _current_module = _current_module->selected_child;
                    _current_module->set_unclean();
                } else {
                    _current_module->activate_two();
                }
                break;
        }
    }
    
    int module_manager_t::print_screen(screen_printer_t &printer) {
        if (_current_module->is_unclean()) {
            return _current_module->print_screen(printer);
        }

        return 0;
    }
}