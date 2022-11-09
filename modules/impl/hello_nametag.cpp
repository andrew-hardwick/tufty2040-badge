#include "hello_nametag.h"

#include "../badge_module.h"

namespace badge {
    hello_nametag_t::hello_nametag_t() :
        _backgrounds(),
        _foregrounds()
    {

    }
    
    hello_nametag_t::~hello_nametag_t() {
        
    }
    
    int hello_nametag_t::print_screen(screen_printer_t &printer) {
        if (!_initialized) {
            printer.create_pen("hello_nametag_inner", 255, 255, 255);
            printer.create_pen("hello_nametag_black", 0, 0, 0);

            printer.create_pen("hello_nametag_red", 255, 0, 0);
            printer.create_pen("hello_nametag_yellow", 255, 255, 0);
            printer.create_pen("hello_nametag_green", 0, 255, 0);
            printer.create_pen("hello_nametag_blue", 0, 0, 255);
            printer.create_pen("hello_nametag_cyan", 0, 255, 255);
            printer.create_pen("hello_nametag_magenta", 255, 0, 255);

            _backgrounds.push_back("hello_nametag_red");
            _backgrounds.push_back("hello_nametag_yellow");
            _backgrounds.push_back("hello_nametag_green");
            _backgrounds.push_back("hello_nametag_blue");
            _backgrounds.push_back("hello_nametag_cyan");
            _backgrounds.push_back("hello_nametag_magenta");

            _foregrounds.push_back("hello_nametag_inner");
            _foregrounds.push_back("hello_nametag_black");
            _foregrounds.push_back("hello_nametag_black");
            _foregrounds.push_back("hello_nametag_inner");
            _foregrounds.push_back("hello_nametag_black");
            _foregrounds.push_back("hello_nametag_inner");

            _initialized = true;
        }

        pimoroni::Point text_location(0, 32);

    //Red Background
        printer.clear_screen(_backgrounds[_color_index]);

    //White Rectangle
        printer.draw_rect("hello_nametag_inner", 0, 80, 320, 120);

        auto foreground_color = _foregrounds[_color_index];

    //HELLO
        text_location.x = 85;
        text_location.y = 25;
        printer.draw_text(foreground_color, "sans_bold", "HELLO", text_location, 1.5, 1);
        
    //My Name Is
        text_location.y += 32;
        printer.draw_text(foreground_color, "sans", "My Name Is:", text_location, .75, 1);

    //He/Him (bottom)
        text_location.x = 110;
        text_location.y = 220;
        printer.draw_text(foreground_color, "sans", "He/Him", text_location, .75, 1);

    //Drew (name)
        text_location.x = 25;
        text_location.y = 140;
        printer.draw_text("hello_nametag_black", "sans_bold", "Drew", text_location, 3.5, 8);

       _clean_state = true;

       // _color_index = 1 - _color_index;
       //move_selection(1);

       return 0;
    }

    void hello_nametag_t::move_selection(int8_t &direction) {
        _color_index += direction;

        if (_color_index < 0) _color_index = _backgrounds.size() - 1;
        if (_color_index >= _backgrounds.size()) _color_index = 0;

        _clean_state = false;
    }

    void hello_nametag_t::select(badge_module_t &result) {

    }

    void hello_nametag_t::clear(badge_module_t &result) {
        
    }
}