/*
Brandon Ellis
01/29/2022
CSE121C Week 4 Assignment
*/


#include <stdio.h>
#include <stdlib.h>

//define variables for task 1
int aNum = 0;
int bNum = 0;

//define structure for task 2
struct account{
    int number;
    char name[16];
    float balance;
};

//Initialize functions
void minimums(int* a, int* b);
void writeAccount(struct account*);
void readAccount(struct account*);



void main(){
    //task 1
    int* aPoint = &aNum;
    int* bPoint = &bNum;
    minimums(aPoint, bPoint);

    //task 2
    //create instance of an account after allocating memory space
    struct account* acct = malloc(sizeof(struct account));
   
    writeAccount(acct);
    readAccount(acct);

    free(acct);

}


//TASK 1: MINIMUM NUMBERS
void minimums(int* a, int* b){
    printf("A = %d, B = %d\n",*a,*b);
    printf("Enter a number for A:");
    scanf("%d",a);
    printf("Enter a number for B:");
    scanf("%d",b);
    if(*a >= *b){
        printf("Minimum is %d\n",*b);
    }
    else{
        printf("Minimum is %d\n",*a);
    }
    printf("A = %d, B = %d\n",*a,*b);
}


//TASK 2: BANK ACCOUNT
void writeAccount(struct account* a){
    printf("\n\n");
    printf("What is the account number?: ");
    scanf("%d", &a->number);
    printf("What is the account name?: ");
    scanf("%s", a->name);
    printf("What is the account balance?: ");
    scanf("%f", &a->balance);
}

void readAccount(struct account* a){
    printf("\nAccount information:\n");
    printf("# %d\nNAME: %s\nBALANCE: $%.2f",a->number, a->name, a->balance);
}