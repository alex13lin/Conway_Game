//
// Created by a1016 on 2023/2/25.
//

#ifndef CONWAY_GAME_CELL_H
#define CONWAY_GAME_CELL_H
#define ALIVE 1
#define DEAD 0

#include <iostream>

namespace Conway {

    class Cell {
    public:
        Cell();

        void refresh_state();

        void change_state(int);

        void set_state_alive();

        int get_state() const;

        void output_cell() const;

    private:
        int _state, _next_state;
    };

} // Conway

#endif //CONWAY_GAME_CELL_H
