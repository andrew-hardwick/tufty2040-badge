//#include "modules/build_module_tree.hpp"
#include "modules/module_manager.h"
#include "display/display_manager.h"
#include "utility/board_manager.h"
#include "utility/rand_utils.h"
// #include "display/screen_manager.h"

using namespace badge;

int main() {
  seed_random();
  board_manager_t board_manager;
  display_manager_t display_manager;
  module_manager_t module_manager;

  pressed_button button = pressed_button::NONE;

  //loop forever
  while(true) {
    board_manager.tick(button);
    
    module_manager.handle_button(button);

    if (board_manager.is_unclean()) {
      display_manager.update_board(board_manager);
    }

    display_manager.update_module(module_manager);

    sleep_ms(1000 / 60);
  }

    return 0;
}