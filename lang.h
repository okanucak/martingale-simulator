struct langDict
{
    char *YOUR_BALANCE;
    char *YOUR_TARGET;
    char *MIN_BET;
    char *ZERO_TEXT;
    char *ODD_TEXT;
    char *EVEN_TEXT;
    char *YOUR_CHOICE;
    char *BET;
    char *WAIT;
    char *INCOMING_NUMBER;
    char *LUCKY;
    char *UNLUCKY;
    char *CRITICAL;
    char *SORRY;
    char *YOU_WIN;
    char *YOU_LOST;
};

struct langDict trDict;
struct langDict enDict;

struct language
{
    char *code;
    struct langDict dict;
};

const int TR = 0;
const int EN = 1;

struct language langs[2];
struct language lang;

void setDicts() {
    trDict.YOUR_BALANCE = "Bakiyeniz";
    enDict.YOUR_BALANCE = "Your Balance";

    trDict.YOUR_TARGET = "Hedefiniz";
    enDict.YOUR_TARGET = "Your Target";

    trDict.MIN_BET = "Minimum Bahis";
    enDict.MIN_BET = "Minimum Bet";

    trDict.ZERO_TEXT = "Sıfır";
    enDict.ZERO_TEXT = "Zero";

    trDict.ODD_TEXT = "Tek";
    enDict.ODD_TEXT = "Odd";

    trDict.EVEN_TEXT = "Çift";
    enDict.EVEN_TEXT = "Even";

    trDict.YOUR_CHOICE = "Seçiminiz";
    enDict.YOUR_CHOICE = "Your Choice";

    trDict.BET = "Bahis";
    enDict.BET = "Bet";

    trDict.WAIT = "Dönüyor...";
    enDict.WAIT = "Spinning...";

    trDict.INCOMING_NUMBER = "Gelen sayı";
    enDict.INCOMING_NUMBER = "Incoming number";

    trDict.LUCKY = "İyisin :)";
    enDict.LUCKY = "You are good :)";

    trDict.UNLUCKY = "Sıkıntı yok beti arttırıyorum ;)";
    enDict.UNLUCKY = "No problem, I am increasing the bet ;)";

    trDict.CRITICAL = "Durum kritik :(";
    enDict.CRITICAL = "The situation is critical :(";

    trDict.SORRY = ":(";
    enDict.SORRY = ":(";

    trDict.YOU_WIN = "+++Kazandın+++";
    enDict.YOU_WIN = "+++You won+++";

    trDict.YOU_LOST = "---Kaybettin---";
    enDict.YOU_LOST = "---You lost---";
}

void initialLangs() {
    setDicts();

    langs[TR].code = "tr";
    langs[TR].dict = trDict;

    langs[EN].code = "en";
    langs[EN].dict = enDict;
}

void setLang(int langIndex) {
    lang = langs[langIndex];
}
