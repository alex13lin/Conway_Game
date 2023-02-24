#include "Life.h"
#include <unistd.h>

int main() {
    Conway::Life life(5, 5);
    life.set_cell_state_alive(1, 2);
    life.set_cell_state_alive(2, 2);
    life.set_cell_state_alive(3, 2);
    while (true) {
        life.run();
        sleep(1.5);
    }

    return 0;
}
