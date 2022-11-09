#include "badge_module.h"

namespace badge {
    bool badge_module_t::is_unclean() {
        return !_clean_state;
    }

    void badge_module_t::set_unclean() {
        _clean_state = false;
    }
}