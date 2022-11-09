#include "rand_utils.h"

#include <cstdlib>
#include <pico/stdlib.h>
#include <hardware/regs/rosc.h>
#include <hardware/regs/addressmap.h>

namespace badge {
    void seed_random() {
        uint32_t random = 0x811c9dc5;
        uint8_t next_byte = 0;
        volatile uint32_t *rnd_reg = (uint32_t *)(ROSC_BASE + ROSC_RANDOMBIT_OFFSET);

        for (int i = 0; i < 16; i++) {
            for (int k = 0; k < 8; k++) {
            next_byte = (next_byte << 1) | (*rnd_reg & 1);
            }

            random ^= next_byte;
            random *= 0x01000193;
        }

        srand(random);
    }
}