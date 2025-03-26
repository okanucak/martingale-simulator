struct messages
{
    char *YOUR_BALANCE;
    char *YOUR_TARGET;
    char *START_BALANCE;
    char *ZERO_TEXT;
    char *ODD_TEXT;
    char *EVEN_TEXT;
    char *YOUR_CHOICE;
    char *BALANCE;
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

struct messages trMessages;
struct messages enMessages;

struct messages langs[2];
struct messages lang;

const int TR = 0;
const int EN = 1;

void setMessages() {
    trMessages.YOUR_BALANCE = "Bakiyeniz";
    enMessages.YOUR_BALANCE = "Your Balance";

    trMessages.YOUR_TARGET = "Hedefiniz";
    enMessages.YOUR_TARGET = "Your Target";

    trMessages.START_BALANCE = "Başlangıç";
    enMessages.START_BALANCE = "Starting";

    trMessages.ZERO_TEXT = "Sıfır";
    enMessages.ZERO_TEXT = "Zero";

    trMessages.ODD_TEXT = "Tek";
    enMessages.ODD_TEXT = "Odd";

    trMessages.EVEN_TEXT = "Çift";
    enMessages.EVEN_TEXT = "Even";

    trMessages.YOUR_CHOICE = "Seçiminiz";
    enMessages.YOUR_CHOICE = "Your Choice";

    trMessages.BALANCE = "Bakiye";
    enMessages.BALANCE = "Balance";

    trMessages.BET = "Bahis";
    enMessages.BET = "Bet";

    trMessages.WAIT = "Dönüyor...";
    enMessages.WAIT = "Spinning...";

    trMessages.INCOMING_NUMBER = "Gelen sayı";
    enMessages.INCOMING_NUMBER = "Incoming number";

    trMessages.LUCKY = "İyisin :)";
    enMessages.LUCKY = "You are good :)";

    trMessages.UNLUCKY = "Sıkıntı yok beti arttırıyorum ;)";
    enMessages.UNLUCKY = "No problem, I am increasing the bet ;)";

    trMessages.CRITICAL = "Durum kritik :(";
    enMessages.CRITICAL = "The situation is critical :(";

    trMessages.SORRY = ":(";
    enMessages.SORRY = ":(";

    trMessages.YOU_WIN = "+++Kazandın+++";
    enMessages.YOU_WIN = "+++You won+++";

    trMessages.YOU_LOST = "---Kaybettin---";
    enMessages.YOU_LOST = "---You lost---";

    langs[TR] = trMessages;
    langs[EN] = enMessages;
}

void setLang(int langIndex) {
    lang = langs[langIndex];
}
