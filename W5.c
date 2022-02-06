/*
Brandon Ellis
02-05-2022
CSE121C Week 5 Assignment
*/

#include <stdio.h>
#include <stdlib.h>

//Declare account structure
struct account{
    int number;
    char name[16];
    float balance;
    struct account* next; 
};

//Initialize Functions
void createAccount(struct account** first, struct account** recent);
void printAccount(struct account* t);
void writeAccount(struct account*);
void showAccounts(struct account* first);
struct account* findAccount(struct account* first);
void editAccount(struct account* first);
void cleanAll(struct account* first);


int main(){

    //Create working variables
    struct account* first_acct = NULL;
    struct account* new_acct = NULL;
    struct account* sel_acct = NULL;
    int userchoice = 0;
    int l = 1;

    //Intro greeting
    printf("Welcome to the account management system!\n");
    //Main menu loop
    while(l){
        printf("MAIN MENU: \n[1] CREATE ACCOUNT\n[2] SHOW ALL ACCOUNTS\n[3] FIND ACCOUNT\n[4] EDIT ACCOUNT\n\n[0] QUIT\n");
        scanf("%d",&userchoice);

        //Menu switch statement
        switch (userchoice){
            //Quit
            case 0:
            printf("Exiting program...\n");
            l = 0;
            break;
            //Create Account
            case 1:
            createAccount(&first_acct, &new_acct);
            break;
            //Show all Accounts
            case 2:
            showAccounts(first_acct);
            break;
            //Show one account
            case 3:
            sel_acct = findAccount(first_acct);
            if(sel_acct != NULL){
                printAccount(sel_acct);
            }
            break;
            //Edit one account
            case 4:
            sel_acct = findAccount(first_acct);
            if(sel_acct != NULL){
                writeAccount(sel_acct);
                printf("Account edited.\n");
            }
            break;
            //Default for invalid entry
            default:
            printf("Invalid entry, please enter again.\n");
        }
    }

    cleanAll(first_acct);
    return 0;
}


void createAccount(struct account** first, struct account** recent){
    struct account* new = NULL;
    new = malloc(sizeof(struct account));
    new->next = NULL;
    writeAccount(new);
    if (*first == NULL){
        *first = new;
        *recent = new;
    }
    else{
        (*recent)->next = new;
        *recent = new;
    }
    printf("Account created!\n");
}

void writeAccount(struct account* a){
    printf("\n");
    printf("What is the account number?: ");
    scanf("%d", &a->number);
    printf("What is the account name?: ");
    scanf("%s", a->name);
    printf("What is the account balance?: ");
    scanf("%f", &a->balance);
    printf("\n");
}

void printAccount(struct account* a){
    printf("#%d NAME: %s BALANCE: $%.2f\n",a->number, a->name, a->balance);
}

void showAccounts(struct account* list){
    struct account* t = list;
    if (t == NULL){
        printf("There are no accounts to display.\n");
    }
    else{
        printf("Accounts on file:\n");
        
        while(t){
            printAccount(t);
            t = t->next;
        }
    }
}

struct account* findAccount(struct account* first){
    int acctKey = 0;
    printf("Enter the account number to search:\n");
    scanf("%d",&acctKey);
    struct account* i = first;
    while(i){
        if(i->number == acctKey){
            printf("Account found!\n");
            return i;
        }
        i = i->next;
    }
    printf("Account not found!\n");
    return NULL;
}

void cleanAll(struct account* first){
    struct account* next = first;
    while(first){
        next = first->next;
        free(first);
        first = next;
    }
}