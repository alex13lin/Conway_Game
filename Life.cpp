//
// Created by a1016 on 2023/2/25.
//

#include "Life.h"

namespace Conway {
    Life::Life(int height, int width) {
        _height = height;
        _width = width;
        _map = new Cell *[_height];
        for (int i = 0; i < _height; i++)_map[i] = new Cell[_width];
    }

    void Life::run() {
        output_cells();
        generate_next_map();
    }

    void Life::output_cells() {
        for (int i = 0; i < _height; i++) {
            for (int j = 0; j < _width; j++)
                _map[i][j].output_cell();
            std::cout << std::endl;
        }
    }

    void Life::generate_next_map() {
        for (int i = 0; i < _height; i++) {
            for (int j = 0; j < _width; j++)
                _map[i][j].change_state(get_neighbor_sum(i, j));
            std::cout << std::endl;
        }
        for (int i = 0; i < _height; i++)
            for (int j = 0; j < _width; j++)
                _map[i][j].refresh_state();
    }

    int Life::get_neighbor_sum(int i, int j) {
        int neighbor_sum = 0;
        for (int _i = i - 1; _i <= i + 1; _i++)
            for (int _j = j - 1; _j <= j + 1; _j++) {
                if (_i == i && _j == j)continue;
                neighbor_sum += get_cell_state(_i, _j);
            }
        return neighbor_sum;
    }

    int Life::get_cell_state(int i, int j) {
        if (i >= 0 && j >= 0 && i < _height && j < _width)
            return _map[i][j].get_state();
        return 0;
    }

    void Life::set_cell_state_alive(int i, int j) {
        if (i >= 0 && j >= 0 && i < _height && j < _width)
            _map[i][j].set_state_alive();
    }

    void Life::delete_cells() {
        for (int i = 0; i < _height; i++)delete[] _map[i];
        delete[] _map;
    }
} // Conway