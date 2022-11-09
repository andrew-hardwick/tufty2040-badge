#include "board_manager.h"

#include <hardware/adc.h>

#include <tufty2040.hpp>
#include <button.hpp>


namespace badge {
    board_manager_t::board_manager_t() :
        button_a(pimoroni::Tufty2040::A, pimoroni::Polarity::ACTIVE_HIGH, 1500),
        button_b(pimoroni::Tufty2040::B, pimoroni::Polarity::ACTIVE_HIGH, 1500),
        button_c(pimoroni::Tufty2040::C, pimoroni::Polarity::ACTIVE_HIGH, 1500),
        button_up(pimoroni::Tufty2040::UP, pimoroni::Polarity::ACTIVE_HIGH, 1500),
        button_down(pimoroni::Tufty2040::DOWN, pimoroni::Polarity::ACTIVE_HIGH, 1500),
        tufty(),
        pressed_button_queue()
    {
        //setup light sensor
        init_lux_sensor();

        tufty.led(31);
    }

    void board_manager_t::init_lux_sensor() {
        adc_init();
        adc_gpio_init(LUX_PIN);
        adc_select_input(LUX_ADC);

        gpio_init(LUX_PULLUP);
        gpio_set_dir(LUX_PULLUP, GPIO_OUT);
        gpio_put(LUX_PULLUP, 1);
    }

    board_manager_t::~board_manager_t() {

    }

    bool board_manager_t::is_unclean() {
        return !clean_state;
    }

    void board_manager_t::tick(pressed_button &button) {
        current_lux = adc_read();

        if ((current_lux > set_lux && current_lux - set_lux > 10) || (set_lux > current_lux && set_lux - current_lux > 10)) {
            clean_state = false;
        }

        button = pressed_button::NONE;

        //todo implement queue here maybe?
        if (button_up.read()) {
            button = pressed_button::UP;
        }
        if (button_down.read()) {
            button = pressed_button::DOWN;
        }
        if (button_a.read()) {
            button = pressed_button::A;
        }
 //       button = pressed_button::;
    }

    uint16_t board_manager_t::get_lux() {
        set_lux = current_lux;

        clean_state = true;

        return set_lux;
    }
}