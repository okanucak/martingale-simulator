#include <stdlib.h>

int randomdNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}
