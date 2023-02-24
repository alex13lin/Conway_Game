//
// Created by a1016 on 2023/2/25.
//

#ifndef CONWAY_GAME_LIFE_H
#define CONWAY_GAME_LIFE_H

#include "Cell.h"

namespace Conway {

    class Life {
    public:
        Life(int, int);

        void run();

        void set_cell_state_alive(int, int);

    private:
        Cell **_map;
        int _height, _width;

        void output_cells();

        void generate_next_map();

        int get_neighbor_sum(int, int);

        int get_cell_state(int, int);
    };

} // Conway

#endif //CONWAY_GAME_LIFE_H
