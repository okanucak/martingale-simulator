#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "lang.h"
#include "marsi.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));

    setMessages();
    int langIndex = TR;
    if (argc > 1) {
        if (strcmp(toLower(argv[1]), "en") == 0) {
            langIndex = EN;
        }
    }
    setLang(langIndex);

    marsi();

    return 0;
}
