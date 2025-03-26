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
    inputAmount(&balance, lang.YOUR_BALANCE);
    inputAmount(&target, lang.YOUR_TARGET);
    inputAmount(&startBet, lang.MIN_BET);

    inputChoice();

    if (startBet > balance) {
        startBet = balance;
    }

    bet = startBet;

    while (balance > 0 && balance < target) {
        spin();
    }

    if (balance >= target) {
        printf("\n%s\n", lang.YOU_WIN);
    } else {
        printf("\n%s\n", lang.YOU_LOST);
    }
}

void spin() {
    balance -= bet;

    printf("\n");
    printf("%s\t:%d\n", lang.YOUR_BALANCE, balance);
    printf("%s\t\t:%d\n", lang.BET, bet);
    printf("%s\n", lang.WAIT);

    for (long i = 1; i <= 9999999999; i++);
    
    int number = randomdNumber(0, 36);

    int result = 0;
    if (number != ZERO_VALUE) {
        printf("%s\t:%d\n", lang.INCOMING_NUMBER, number);
        if (number % 2 == choice % 2) {
            result = 1;
        }
    } else {
        printf("%s:\t%s\n", lang.INCOMING_NUMBER, lang.ZERO_TEXT);
    }

    if (result) {
        balance += bet * 2;
        bet = startBet;
        printf("%s\n", lang.LUCKY);
    } else {
        bet *= 2;
        if (balance > bet) {
            printf("%s\n", lang.UNLUCKY);
        } else if (balance > 0) {
            bet = balance;
            printf("%s\n", lang.CRITICAL);
        } else {
            printf("%s\n", lang.SORRY);
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
