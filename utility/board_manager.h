#ifndef BOARD_MANAGER_H
#define BOARD_MANAGER_H

#include <queue>

#include <tufty2040.hpp>
#include <button.hpp>

namespace badge {
    static const uint8_t LUX_PIN = 26;
    static const uint8_t LUX_ADC = 0;
    static const uint8_t LUX_PULLUP = 27;

    enum pressed_button { NONE, A, B, C, UP, DOWN };

    class board_manager_t {
        public: 
            board_manager_t();
            ~board_manager_t();

            pressed_button tick();
            uint16_t get_lux();
            
            bool is_unclean();

            pimoroni::Tufty2040 tufty;
        private:
            pimoroni::Button button_a;
            pimoroni::Button button_b;
            pimoroni::Button button_c;
            pimoroni::Button button_up;
            pimoroni::Button button_down;

            bool clean_state = true;

            uint16_t current_lux = 0;
            uint16_t set_lux = 0;

            std::queue<pressed_button> pressed_button_queue;

            void init_lux_sensor();
    };
}

#endif
