#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getBet(int balance);
void clearArray(int *arr);
void shuffleArray(int *arr);
void treasureHunt(const int *arr, int *balance, int bet, int player_guess);
int getGuess(void);
int getBalance(void);

int main() {
    int holes[3];
    int balance;
    int seed;
    int bet;
    int guess;
    
    printf("Enter the seed: ");
    scanf("%d", &seed);
    srand(seed);
    
    balance = getBalance();
    
    while (balance > 0) {
        clearArray(holes);
        shuffleArray(holes);
        
        bet = getBet(balance);
        if (bet == 0) {
            printf("Exiting the game. Thank you for playing!\n");
            puts("");
            printf("Your cash balance is now = %d\n", balance);
            
            return 0;
        }
        
        guess = getGuess();
        treasureHunt(holes, &balance, bet, guess);
        printf("Your cash balance is now = %d\n", balance);
    }
    
    printf("Sorry, you're out of cash. Better luck next time! Thank you for playing.\n");
    return 0;
}

int getBalance(void) {
    int balance;
    do {
        printf("----Enter your starting cash balance---- : ");
        scanf("%d", &balance);
        if (balance <= 0) {
            printf("The balance should be positive. Try again.\n");
        }
    } while (balance <= 0);
    return balance;
}

int getBet(int balance) {
    int bet;
    while (1) {
        puts("");
        printf("Enter the amount you want to bet (0 to stop): ");
        scanf("%d", &bet);
        if (bet == 0) {
            return 0;
        }
        else if (bet < 0) {
            printf("The bet should be positive. Try again.\n");
        }
        else if (bet > balance) {
            printf("Not enough money. Try again!\n");
        }
        else {
            return bet;
        }
    }
}

void clearArray(int *arr) {
    for (int i = 0; i < 3; i++) {
        arr[i] = 0;
    }
}

void shuffleArray(int *arr) {
    int treasure_pos = rand() % 3;
    arr[treasure_pos] = 1;
}

int getGuess(void) {
    int guess;
    while (1) {
        puts("");
        printf("Guess the hole where the treasure is hidden...\n");
        scanf("%d", &guess);
        if (guess < 1 || guess > 3) {
            printf("There are 3 holes. Try again.\n");
        }
        else {
            return guess;
        }
    }
}

void treasureHunt(const int *arr, int *balance, int bet, int player_guess) {
    int index = player_guess - 1;
    if (arr[index] == 1) {
        printf("You found the treasure! ");
        *balance += bet;
    }
    else {
        printf("No treasure here! ");
        *balance -= bet;
    }
    printf("The holes are as follows: ");
    for (int i = 0; i < 3; i++) {
        printf("%d", arr[i]);
        if (i < 2) {
            printf(", ");
        }
    }
    printf("\n");
}