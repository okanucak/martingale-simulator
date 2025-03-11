#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lang/turkish.h"

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
void inputAmount(int *amount, char message[255]);
void inputChoice();
void showAmounts();
void spin();
int getNumber();


int main() {

    initial();
    
    run();
    
    finitial();
    
    return 0;
}


void initial() {
    srand(time(NULL));

    inputAmount(&balance, YOUR_BALANCE);
    inputAmount(&target, YOUR_TARGET);
    inputAmount(&startBet, START_BALANCE);

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
        puts(YOU_WIN);
    } else {
        puts(YOU_LOST);
    }
}

void spin() {
    int number = getNumber();

    printf("\n%s\n\n", WAIT);

    for (int i = 1; i <= 2000000000; i++);

    if (number != ZERO_VALUE) {
        printf("%s:\t%d\n", INCOMING_NUMBER, number);
    } else {
        printf("%s:\t%s\n", INCOMING_NUMBER, ZERO_TEXT);
    }

    if (number != ZERO_VALUE && number % 2 == choice % 2) {
        balance += bet;
        bet = startBet;
        puts(LUCKY);
    } else {
        balance -= bet;
        bet *= 2;
        if (balance > bet) {
            puts(UNLUCKY);
        } else if (balance > 0) {
            bet = balance;
            puts(CRITICAL);
        } else {
            puts(SORRY);
        }
    }
}

void inputAmount(int *amount, char message[255]) {
    char input[10];

    do {
        printf("%s\t: ", message);
        scanf("%s", input);
        *amount = atoi(input);
    } while (*amount < 1);
}

void showAmounts() {
    printf("\n%s\t:\t%d\n%s\t:\t%d\n", BALANCE, balance, BET, bet);
}

void inputChoice() {
    char input[10];

    do {
        printf("\n%s\t\t(%d)\n%s\t\t(%d)\n%s\t:", ODD, ODD_VALUE, EVEN, EVEN_VALUE, YOUR_CHOICE);
        scanf("%s", input);
        choice = atoi(input);
    } while (choice != ODD_VALUE && choice != EVEN_VALUE);
}

int getNumber() {
    return rand() % 37;
}

