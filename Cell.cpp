//
// Created by a1016 on 2023/2/25.
//

#include "Cell.h"

namespace Conway {
    Cell::Cell() {
        _state = DEAD;
        _next_state = DEAD;
    }

    void Cell::refresh_state() {
        _state = _next_state;
    }

    void Cell::output_cell() const {
        if (_state == ALIVE) std::cout << "⬜";
        else if (_state == DEAD)std::cout << "⬛";
    }

    void Cell::change_state(int neighbor_sum) {
        if (_state == ALIVE) {
            if (neighbor_sum == 2 || neighbor_sum == 3) _next_state = ALIVE;
            else _next_state = DEAD;
        } else if (_state == DEAD && neighbor_sum == 3) _next_state = ALIVE;
    }

    int Cell::get_state() const {
        return _state;
    }

    void Cell::set_state_alive() {
        _state = ALIVE;
    }
} // Conway