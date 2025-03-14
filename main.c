#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "lang.h"

const int ZERO_VALUE = 0;
const int ODD_VALUE = 1;
const int EVEN_VALUE = 2;

int balance;
int target;
int startBet;
int bet;
int choice;

void initial();
void run();
void finitial();
void inputAmount(int *amount, char *message);
void inputChoice();
void showAmounts();
void spin();
int getNumber();

struct messages lang;


int main(int argc, char *argv[]) {

    srand(time(NULL));

    setMessages();
    lang = trMessages;
    if (argc > 1) {
        if (strcmp(argv[1], "en") == 0) {
            lang = enMessages;
        }
    }

    initial();
    
    run();
    
    finitial();

    return 0;
}


void initial() {
    inputAmount(&balance, lang.YOUR_BALANCE);
    inputAmount(&target, lang.YOUR_TARGET);
    inputAmount(&startBet, lang.START_BALANCE);

    if (startBet > balance) {
        startBet = balance;
    }

    inputChoice();

    bet = startBet;
}

void run() {
    while (balance > 0 && balance < target) {
        showAmounts();
        spin();
    }
}

void finitial() {
    showAmounts();

    if (balance >= target) {
        puts(lang.YOU_WIN);
    } else {
        puts(lang.YOU_LOST);
    }
}

void spin() {
    int number = getNumber();

    printf("\n%s\n\n", lang.WAIT);

    for (int i = 1; i <= 2000000000; i++);

    if (number != ZERO_VALUE) {
        printf("%s:\t%d\n", lang.INCOMING_NUMBER, number);
    } else {
        printf("%s:\t%s\n", lang.INCOMING_NUMBER, lang.ZERO_TEXT);
    }

    if (number != ZERO_VALUE && number % 2 == choice % 2) {
        balance += bet;
        bet = startBet;
        puts(lang.LUCKY);
    } else {
        balance -= bet;
        bet *= 2;
        if (balance > bet) {
            puts(lang.UNLUCKY);
        } else if (balance > 0) {
            bet = balance;
            puts(lang.CRITICAL);
        } else {
            puts(lang.SORRY);
        }
    }
}

void inputAmount(int *amount, char *message) {
    char input[10];

    do {
        printf("%s\t: ", message);
        scanf("%s", input);
        *amount = atoi(input);
    } while (*amount < 1);
}

void showAmounts() {
    printf("\n%s\t:\t%d\n%s\t:\t%d\n", lang.BALANCE, balance, lang.BET, bet);
}

void inputChoice() {
    char input[10];

    do {
        printf("\n%s\t\t(%d)\n%s\t\t(%d)\n%s\t:", lang.ODD_TEXT, ODD_VALUE, lang.EVEN_TEXT, EVEN_VALUE, lang.YOUR_CHOICE);
        scanf("%s", input);
        choice = atoi(input);
    } while (choice != ODD_VALUE && choice != EVEN_VALUE);
}

int getNumber() {
    return rand() % 37;
}
