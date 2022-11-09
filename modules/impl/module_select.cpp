#include "module_select.h"

#include "../badge_module.h"
#include "hello_nametag.h"
#include "random_monster.h"

namespace badge {
    module_select_t::module_select_t() :
        _children(),
        _children_names()
    {
        _children.push_back(new hello_nametag_t());
        _children.push_back(new random_monster_t());

        _children_names.push_back("Name Tag");
        _children_names.push_back("Random Monster");

        for(uint8_t i = 0; i < _children.size(); i++) {
            _children[i]->parent = this;
        }

        _selected_index = 0;
        selected_child = _children[_selected_index];

        _clean_state = false;
    }
    
    module_select_t::~module_select_t() {
        
    }
    
    int module_select_t::print_screen(screen_printer_t &printer) {
        if (!_initialized) {
            printer.create_pen("module_select_white", 255, 255, 255);
            printer.create_pen("module_select_black", 0, 0, 0);

            printer.create_pen("module_select_red", 255, 0, 0);
            printer.create_pen("module_select_yellow", 255, 255, 0);
            printer.create_pen("module_select_green", 0, 255, 0);
            printer.create_pen("module_select_blue", 0, 0, 255);
            printer.create_pen("module_select_cyan", 0, 255, 255);
            printer.create_pen("module_select_magenta", 255, 0, 255);

            _initialized = true;
        }

        size_t option_count = _children.size();

        pimoroni::Point loc(0, 0);

        printer.clear_screen("module_select_black");

        //todo implement scrolling screen here
        for(uint8_t i = 0; i < option_count; i++) {
            loc.y = 30 * i;
            if (i == _selected_index) {
                printer.draw_text("module_select_cyan", "bitmap8", _children_names[i], loc, 3, 1);
            } else {
                printer.draw_text("module_select_white", "bitmap8", _children_names[i], loc, 3, 1);
            }
        }

       _clean_state = true;

       return 0;
    }

    void module_select_t::move_selection(int8_t &direction) {
        _selected_index += direction;

        if (_selected_index < 0) _selected_index = _children.size() - 1;
        if (_selected_index >= _children.size()) _selected_index = 0;

        selected_child = _children[_selected_index];

        _clean_state = false;
    }

    void module_select_t::activate_one() {

    }

    void module_select_t::activate_two() {

    }
}