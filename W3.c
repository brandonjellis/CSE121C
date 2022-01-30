/*
Brandon Ellis
01/22/2022
CSE 121C Week 3 Assingment
*/

#include <stdio.h>
#include <stdlib.h>


//function for task 2
void displayBinary(unsigned int number){
    for(int i=31;i>=0;i--){
        printf("%d",(number & (1<<i))>0);
    }
    printf("\n");
}

//Task 1 String hex converter
//####################################

int main(){

    char userString[16] = "";
    printf("Enter a word:\n");
    scanf("%s",&userString);

    for (int i=0;i<=14;i++){  
        if(userString[i] != '\0'){
            printf("%X ",userString[i]);
        }
    }
    printf("\n\n");


//Task 2 Binary converter
//############################################
    int userNumber = 0;
    printf("Give a number to convert to binary:\n");
    scanf("%u",&userNumber);
    displayBinary(userNumber);
    printf("\n\n");


// Task 3 bitwise operators
//################################################

unsigned int num1 = 56;
unsigned int num2 = 18;

printf("Variable A: ");
displayBinary(num1);
printf("Variable B: ");
displayBinary(num2);

printf("Result of:\n");
printf("A & B = ");
displayBinary(num1&num2);

printf("Result of:\n");
printf("A | B = ");
displayBinary(num1|num2);

printf("Result of:\n");
printf("A ^ B = ");
displayBinary(num1^num2);

printf("Result of:\n");
printf("~A = ");
displayBinary(~num1);

printf("Result of:\n");
printf("A << B = ");
displayBinary(num1<<num2);

printf("Result of:\n");
printf("A >> B = ");
displayBinary(num1>>num2);
}

