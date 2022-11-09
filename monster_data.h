#include <string>
#include <stdio.h>
#include "pico/stdlib.h"


using std::string;

struct monster_data {
  string name;
  string data;
};

monster_data monsters[2] = {
  { "Acolyte", "AC 2 HD1 (4hp) ATT 1 x Mace" },
  { "White Ape", "AC 6 HD4 (18hp) ATT 2 x claw (1d4) or 1 x thrown rock (1d6)" }
};

monster_data select_random_monster() {
  return monsters[std::rand() % 2];
}