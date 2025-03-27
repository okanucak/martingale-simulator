#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "lang.h"
#include "marsi.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));

    initialLangs();
    int langIndex = TR;
    if (argc > 1) {
        char *langCode = toLower(argv[1]);
        if (strcmp(langCode, langs[EN].code) == 0) {
            langIndex = EN;
        }
    }
    setLang(langIndex);

    marsi();

    return 0;
}
