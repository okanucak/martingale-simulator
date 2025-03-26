#include "marsi.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));

    char *language = "tr";
    if (argc > 1) {
        if (strcmp(argv[1], "en") == 0) {
            language = "en";
        }
    }

    marsi(language);

    return 0;
}
