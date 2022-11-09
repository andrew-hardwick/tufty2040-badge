#include "random_monster.h"

#include <experimental/random>

#include <pico/stdlib.h>

#include "../badge_module.h"

namespace badge {
    random_monster_t::random_monster_t() {
        
    }
    
    random_monster_t::~random_monster_t() {
        
    }
    
    int random_monster_t::print_screen(screen_printer_t &printer) {
        if (!_initialized) {
            printer.create_pen("random_monster_white", 255, 255, 255);
            printer.create_pen("random_monster_black", 0, 0, 0);
            printer.create_pen("random_monster_cyan", 50, 255, 255);

            _initialized = true;
        }

        pimoroni::Point loc(5, 5);

        printer.clear_screen("random_monster_black");
        printer.draw_text("random_monster_white", "bitmap8", "DL:", loc, 3, 1);

        loc.x = 45;

        printer.draw_text("random_monster_cyan", "bitmap8", std::to_string(_selected_floor), loc, 3, 1);

        loc.x = 5;
        loc.y = 210;
        printer.draw_text("random_monster_white", "bitmap8", "Press 'B' to Generate", loc, 3, 1);

        loc.x = 5;
        loc.y = 65;
        printer.draw_text("random_monster_cyan", "bitmap8", std::to_string(_selected_monster), loc, 3, 1);

        _clean_state = true;

        return 0;
    }

    void random_monster_t::move_selection(int8_t &direction) {
        _selected_floor += direction;

        if (_selected_floor < 0) _selected_floor = 0;
        if (_selected_floor >= 10) _selected_floor = 10;

        _clean_state = false;
    }

    void random_monster_t::activate_one() {
        //_selected_monster = std::experimental::randint(0, 5);

        _clean_state = false;
    }

    void random_monster_t::activate_two() {
        _selected_monster = std::experimental::randint(0, 5);

        _clean_state = false;
    }
}