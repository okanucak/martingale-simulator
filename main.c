#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lang/turkish.h"

const int ODD_VALUE = 1;
const int EVEN_VALUE = 0;

int balance;
int target;
int startBet;
int bet;
int choice;

char input[10];

void initial();
void showAmounts();
void spin();

int main() {
    initial();

    while (balance > 0 && balance < target) {
        showAmounts();
        spin();
    }

    showAmounts();

    if (balance >= target) {
        puts(YOU_WIN);
    } else {
        puts(YOU_LOST);
    }

    return 0;
}

void initial() {
    srand(time(NULL));

    do {
        printf("%s\t: ", YOUR_BALANCE);
        scanf("%s", input);
        balance = atoi(input);
    } while (balance < 1);

    do {
        printf("%s\t: ", YOUR_TARGET);
        scanf("%s", input);
        target = atoi(input);
    } while (target < 1);
    
    do {
        printf("%s\t: ", START_BALANCE);
        scanf("%s", input);
        startBet = atoi(input);
    } while (!startBet);

    do {
        printf("\n%s\t\t(%d)\n%s\t\t(%d)\n%s\t:", ODD, ODD_VALUE, EVEN, EVEN_VALUE, YOUR_CHOICE);
        scanf("%s", input);
        choice = atoi(input);
    } while (choice != ODD_VALUE && choice != EVEN_VALUE);

    bet = startBet;
}

void showAmounts() {
    printf("\n%s\t:%d\n%s\t:%d\n", BALANCE, balance, BET, bet);
}

void spin() {
    int number;
    
    number = rand() % 36 + 1;

    printf("\n%s\n", WAIT);

    for (int i = 1; i <= 2000000000; i++);

    printf("\n%s%d\n", INCOMING_NUMBER, number);

    if (number % 2 == choice) {
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

