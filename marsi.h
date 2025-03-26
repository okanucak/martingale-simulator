#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "lang.h"

void marsi(char *language);
void spin();
void inputAmount(int *amount, char *message);
void inputChoice();
void showAmounts();

struct messages lang;

const int ZERO_VALUE = 0;
const int ODD_VALUE = 1;
const int EVEN_VALUE = 2;

int balance;
int target;
int startBet;
int bet;
int choice;

void marsi(char *language) {
    setMessages();
    lang = trMessages;
    if (strcmp(language, "en") == 0) {
        lang = enMessages;
    }

    inputAmount(&balance, lang.YOUR_BALANCE);
    inputAmount(&target, lang.YOUR_TARGET);
    inputAmount(&startBet, lang.START_BALANCE);

    inputChoice();

    if (startBet > balance) {
        startBet = balance;
    }

    bet = startBet;

    while (balance > 0 && balance < target) {
        showAmounts();
        spin();
    }

    showAmounts();

    if (balance >= target) {
        puts(lang.YOU_WIN);
    } else {
        puts(lang.YOU_LOST);
    }
}

void spin() {
    printf("\n%s\n\n", lang.WAIT);

    for (int i = 1; i <= 1000000000; i++);
    int number = rand() % 37;

    if (number != ZERO_VALUE) {
        printf("%s\t:%d\n", lang.INCOMING_NUMBER, number);
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
        printf("%s\t:", message);
        scanf("%s", input);
        *amount = atoi(input);
    } while (*amount < 1);
}

void inputChoice() {
    char input[10];

    do {
        printf("%s\t\t(%d)\n", lang.ODD_TEXT, ODD_VALUE);
        printf("%s\t\t(%d)\n", lang.EVEN_TEXT, EVEN_VALUE);
        printf("%s\t:", lang.YOUR_CHOICE);
        scanf("%s", input);
        choice = atoi(input);
    } while (choice != ODD_VALUE && choice != EVEN_VALUE);
}

void showAmounts() {
    printf("\n");
    printf("%s\t:%d\n", lang.YOUR_TARGET, target);
    printf("%s\t\t:%d\n", lang.BALANCE, balance);
    printf("%s\t\t:%d\n", lang.BET, bet);
}
