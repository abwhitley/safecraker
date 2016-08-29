//
//  main.c
//  safeCracker
//
//  Created by Austins Work on 8/10/16.
//  Copyright © 2016 AustinsIronYard. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void win();
void lose();
int runGame();
bool shouldPlaygame = 0;
int main(int argc, const char * argv[]) {
    while (shouldPlaygame == 0)
        runGame();
    return 0;

}
void win(){
   printf("You win!!!\n");
}

void lose(){
   printf("You lose!!!\n");
}
int runGame(){
    fpurge(stdin);
    printf("What is your name?\n");
    
    char name[100] = {'\0'}; // create an array and fill it
    //bool result = 0;
    int numberOfItemsScanner = 0;
    numberOfItemsScanner = scanf("%[^\n]s", name);
    
    printf("Hello %s\n", name);
    
    
    
    int safeCombo[4] = {
        
        arc4random_uniform(4),
        arc4random_uniform(4),
        arc4random_uniform(4),
        arc4random_uniform(4),
        
    };
    
    printf("%d, %d, %d, %d\n", safeCombo[0], safeCombo[1], safeCombo[2], safeCombo[3]);
    int userCombo[4] = {'\0'};
    printf(" %s, Insert 4 numbers: \n", name);
    
    for(int i = 0; i < 4; i++){
        int numberOfItemsScanner = 0;
        numberOfItemsScanner = scanf("%d", &userCombo[i]);
    }
    printf("%d,%d,%d,%d", userCombo[0], userCombo[1], userCombo[2], userCombo[3]);
    printf("\n");
    
    int cont = 0;
    int fail = 0;
    for(int i = 0; i < 4; i++){
        
        if (safeCombo[i] == userCombo[i]) {
            printf("%s, You Unlocked: Lock %d\n",name, i+1);
            cont++;
        }else{
            printf("%s, You Failed lock: %d\n",name, i+1);
            fail++;
            printf("You guessed %d right \n", cont);
            
        }
    }

    printf("Would you like to play?\n");
    printf("to play again enter 0, to not enter 1?\n");
    int choice;
    fpurge(stdin);
    scanf("%d",&choice);
    shouldPlaygame = choice;

    return shouldPlaygame;
}











