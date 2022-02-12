/*
Brandon Ellis
CSE121C Week 6 Final Project.
02-12-2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct book{
unsigned int idNum;
int checkout;
short overdue;
struct book* next;
};

struct acct{
unsigned int acctNum;
char name[32];
struct book* booklist;
struct acct* next;
};

void createAcct();
void createBook();

int main(){

    struct acct* firstAcct = NULL; 
    short loop = 1;
    short userChoice = 0;

    printf("Library Management System V1.0:\n");
    while(loop == 1){
        printf("MAIN MENU:\n");
        printf("[1] CREATE ACCOUNT\n[2] EDIT ACCOUNT\n[3] DELETE ACCOUNT\n[4] LOOKUP ACCOUNT\n[5] CHECKOUT BOOK\n[6] RETURN BOOK\n\n[0] EXIT PROGRAM\n\n");
        scanf("%d",&userChoice);

        switch (userChoice){
            case 1:
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;

            case 6:
            break;

            case 0:
            loop = 0;
            printf("Exiting Program...\n");
            break;

            default:
            printf("Invalid choice, please enter something else."); 
            
        }
    }


    return 0;
}
