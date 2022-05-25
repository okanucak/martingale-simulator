#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int balance, target, startBet, bet, choice;
char input[10];

void initial();
void showAmounts();
void spin();
void winMessage();
void loseMessage();

int main() {
    initial();

    while (balance > 0 && balance < target) {
        showAmounts();
        spin();
    }

    showAmounts();

    if (balance >= target) {
        winMessage();
    } else {
        loseMessage();
    }

    return 0;
}

void initial() {
    srand(time(NULL));

    do {
        printf("Bakiyeniz (TL)\t: ");
        scanf("%s", input);
        balance = atoi(input);
    } while (balance < 1);

    do {
        printf("Hedefiniz (TL)\t: ");
        scanf("%s", input);
        target = atoi(input);
    } while (target < 1);
    
    do {
        printf("Başlangıç (TL)\t: ");
        scanf("%s", input);
        startBet = atoi(input);
    } while (!startBet);

    do {
        printf("\nTek\t\t(1)\nÇift\t\t(2)\nSeçiminiz\t:");
        scanf("%s", input);
        choice = atoi(input);
    } while (choice != 1 && choice != 2);

    bet = startBet;
}

void showAmounts() {
    printf("\nBakiye\t:%d\nBet\t:%d\n", balance, bet);
}

void spin() {
    int number;
    
    number = rand() % 36 + 1;

    printf("\nBekleyiniz...\n");

    for (int i = 1; i <= 1000000000; i++);

    printf("\nGelen sayı: %d\n", number);

    if (number % 2 == choice) {
        balance += bet;
        bet = startBet;
        puts("İyisin :)");
    } else {
        balance -= bet;
        bet *= 2;
        if (balance > bet) {
            puts("Sıkıntı yok beti arttırıyorum ;)");
        } else if (balance > 0) {
            bet = balance;
            puts("Durum kritik :(");
        } else {
            puts(":(");
        }
    }
}

void winMessage() {
    puts("\n+++Kazandın+++");
}

void loseMessage() {
    puts("\n---Kaybettin---");
}

