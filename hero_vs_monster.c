#include <stdio.h>
#include <stdlib.h>

void printYouWin(void);
void printYouLose(void);
int heroAttacks(int atkBonus);
int monsterAttacks(void);
void displayHealth(int heroHealth, int monsterHealth);
void battle(void);

int main() {
    int seed;
    printf("Enter the seed: ");
    scanf("%d", &seed);
    srand(seed);
    battle(); 
    return 0;
}

void printYouWin(void) {
    printf("\n Congratulations! You defeated the monster! \n");
}

void printYouLose(void) {
    printf("\n Game Over! The monster has defeated you! \n");
}

int heroAttacks(int atkBonus) {
    int damage = (rand() % 5 + 1) + (rand() % (atkBonus + 1));
    printf("Hero attacks with %d damage!\n", damage);
    return damage;
}

int monsterAttacks(void) {
    int damage = rand() % 6 + 1;
    printf("Monster attacks with %d damage!\n", damage);
    return damage;
}

void displayHealth(int heroHealth, int monsterHealth) {
    printf("Hero Health: %d | Monster Health: %d\n", heroHealth, monsterHealth);
}

void battle(void) {
    int heroHealth = 20, monsterHealth = 20;
    printf("\n The battle begins! \n");
    displayHealth(heroHealth, monsterHealth);
    
    while (heroHealth > 0 && monsterHealth > 0) {
        monsterHealth -= heroAttacks(2);
        if (monsterHealth <= 0) {
            printYouWin();
            break;
        }
        heroHealth -= monsterAttacks();
        displayHealth(heroHealth, monsterHealth);
    }
    
    if (heroHealth <= 0) {
        printYouLose();
    }
}