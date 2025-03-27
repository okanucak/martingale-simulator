#include <stdlib.h>
#include <ctype.h>

int randomdNumber(int min, int max) {
    if (min > max) {
        int tmp = min;
        min = max;
        max = tmp;
    }
    return rand() % (max - min + 1) + min;
}

char* toLower(char* s) {
    for(char *p = s; *p; p++) {
        *p = tolower(*p);
    }
    return s;
}

char* toUpper(char* s) {
    for(char *p = s; *p; p++) {
        *p = toupper(*p);
    }
    return s;
}
