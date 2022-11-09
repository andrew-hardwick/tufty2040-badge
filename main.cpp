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
  module_manager_t module_manager;
  display_manager_t display_manager;
  //pico_dm::board_setup();

  //debug
   display_manager.debug();

  //loop forever
  while(true) {
    module_manager.handle_button(board_manager.tick());
    //board_manager.tick();

    if (board_manager.is_unclean()) {
      display_manager.update(board_manager);
    }

    if (module_manager.is_unclean()) {
      display_manager.update(module_manager);
    }


    sleep_ms(1000 / 60);
  }

    return 0;
}