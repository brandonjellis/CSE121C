/*
Brandon Ellis
01-15-2022 W22
Week 2 assignment for the CSE121C Course at BYUI
*/

#include <stdio.h>
#include <stdlib.h>


int main(){

//PART 1: NUMERS
//####################################################
    //Initialize variables
    float num1 = 0;
    float num2 = 0;

    //Get user value for both variables
    printf("Enter the value for number 1...");
    scanf("%f",&num1);
    printf("Enter the value for number 2...");
    scanf("%f",&num2);

    //Compare the two variables and print result
    if (num1 > num2)
        printf("%f is the maximum\n%f is the minimum.\n",num1,num2);
    else if (num2 > num1)
        printf("%f is the maximum\n%f is the minimum.\n",num2,num1);
    else 
        printf("The two numbers are equal.\n\n");

//PART 2 STORE
//#####################################################

    //Initialize lists
    char storeMenu[5][15] = {"Milk","Eggs","Bread","Apple","Bananas"};
    float prices[5] = {6.00,2.75,1.99,0.50,1.50};

    //print message and menu
    printf("\n\nWelcome to the store! Here is what is available:\n");
    for (int i=0 ; i<5 ; i++){
        printf("[%d] %s\n", i+1 ,storeMenu[i]);
    }

    //get user choice
    int choice = 0;
    printf("\nPlease make a choice to see price:");
    scanf("%d",&choice);
    int index = choice-1;

    //match input with price and print to user.
    switch (choice){
        case 1:
            printf("The price of Milk is $%.2f.",prices[index]);
            break;
        case 2:
            printf("The price of Eggs is $%.2f.",prices[index]);
            break;
        case 3:
            printf("The price of Bread is $%.2f.",prices[index]);
            break;
        case 4:
            printf("The price of Apples is $%.2f each.",prices[index]);
            break;
        case 5:
            printf("The price of Bananas is $%.2f each.",prices[index]);
            break;
        default:
            printf("Invalid choice.");
    };

//PART 3 BEDTIME
//###########################################################################

    printf("\n\n");
    
    //Initialize
    int age = 0;
    choice = 0;
    int bedtime = 0;
    //get age
    printf("What is the age of the child?");
    scanf("%d",&age);

    //display weekday menu
    char weekdays[7][10] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    for (int i=0 ; i<7 ; i++){
        printf("[%d] %s\n", i+1 ,weekdays[i]);
    }

    //get day
    printf("\nWhat is the day of the week? (Select with the menu above)");
    scanf("%d",&choice);


    //determine bedtime
    switch(choice){
        case 1 ... 5:
            if(age<=5){
                bedtime = 7;
            }
            else if(age>=6 && age<= 10){
                bedtime = 8;
            }
            else{
                bedtime = 9;
            }
            break;
        case 6:
        if(age<=5){
                bedtime = 7;
            }
            else if(age>=6 && age<= 10){
                bedtime = 9;
            }
            else{
                bedtime = 12;
            }
            break;
        case 7:
            if(age<=5){
                bedtime = 7;
            }
            else if(age>=6 && age<= 10){
                bedtime = 9;
            }
            else{
                bedtime = 11;
            }
            break;
        default: 
            printf("Invalid choice");
    }

    //print bedtime message
    printf("The kid's bedtime should be %dpm.",bedtime);



}