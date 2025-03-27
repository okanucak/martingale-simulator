#include <stdio.h>
#include <stdlib.h>

#include "studio.h"

void marsi();
void spin();
void inputAmount(int *amount, char *message);
void inputChoice();

const int ZERO_VALUE = 0;
const int ODD_VALUE = 1;
const int EVEN_VALUE = 2;

int balance;
int target;
int startBet;
int bet;
int choice;

void marsi() {
    inputAmount(&balance, lang.dict.YOUR_BALANCE);
    inputAmount(&target, lang.dict.YOUR_TARGET);
    inputAmount(&startBet, lang.dict.MIN_BET);

    inputChoice();

    if (startBet > balance) {
        startBet = balance;
    }

    bet = startBet;

    while (balance > 0 && balance < target) {
        spin();
    }

    if (balance >= target) {
        printf("\n%s\n", lang.dict.YOU_WIN);
    } else {
        printf("\n%s\n", lang.dict.YOU_LOST);
    }
}

void spin() {
    balance -= bet;

    printf("\n");
    printf("%s\t:%d\n", lang.dict.YOUR_BALANCE, balance);
    printf("%s\t\t:%d\n", lang.dict.BET, bet);
    printf("%s\n", lang.dict.WAIT);

    for (long i = 1; i <= 9999999999; i++);
    
    int number = randomdNumber(0, 36);

    int result = 0;
    if (number != ZERO_VALUE) {
        printf("%s\t:%d\n", lang.dict.INCOMING_NUMBER, number);
        if (number % 2 == choice % 2) {
            result = 1;
        }
    } else {
        printf("%s:\t%s\n", lang.dict.INCOMING_NUMBER, lang.dict.ZERO_TEXT);
    }

    if (result) {
        balance += bet * 2;
        bet = startBet;
        printf("%s\n", lang.dict.LUCKY);
    } else {
        bet *= 2;
        if (balance > bet) {
            printf("%s\n", lang.dict.UNLUCKY);
        } else if (balance > 0) {
            bet = balance;
            printf("%s\n", lang.dict.CRITICAL);
        } else {
            printf("%s\n", lang.dict.SORRY);
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
        printf("%s\t\t(%d)\n", lang.dict.ODD_TEXT, ODD_VALUE);
        printf("%s\t\t(%d)\n", lang.dict.EVEN_TEXT, EVEN_VALUE);
        printf("%s\t:", lang.dict.YOUR_CHOICE);
        scanf("%s", input);
        choice = atoi(input);
    } while (choice != ODD_VALUE && choice != EVEN_VALUE);
}
