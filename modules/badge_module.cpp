#include "badge_module.h"

namespace badge {
    bool badge_module_t::is_unclean() {
        return !_clean_state;
    }
}