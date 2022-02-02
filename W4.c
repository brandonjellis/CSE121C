/*
Brandon Ellis
01/29/2022
CSE121C Week 4 Assignment
*/


#include <stdio.h>
#include <stdlib.h>



//define structure for task 2
struct account{
    int number;
    char name[16];
    float balance;
};

//Initialize functions
int minimums(int* a, int* b);
void writeAccount(struct account*);
void readAccount(struct account*);



int main(void){
    
    //task 1
    //define variables for task 1
    int aNum = 0;
    int bNum = 0;

    printf("A = %d, B = %d\n",aNum,bNum);
    
    printf("Minimum Value is: %d\n",minimums(&aNum, &bNum));

    printf("A = %d, B = %d\n",aNum,bNum);

    //task 2
    //create instance of an account after allocating memory space
    struct account* acct = malloc(sizeof(struct account));
   
    writeAccount(acct);
    readAccount(acct);

    free(acct);
    return 0;
}


//TASK 1: MINIMUM NUMBERS
int minimums(int* a, int* b){

    printf("Enter a number for A:");
    scanf("%d",a);
    printf("Enter a number for B:");
    scanf("%d",b);
    if(*a >= *b){
        return *b;
    }
    else{
        return *a;
    }
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
    printf("\n");
}

void readAccount(struct account* a){
    printf("Account information:\n");
    printf("# %d\nNAME: %s\nBALANCE: $%.2f\n",a->number, a->name, a->balance);
}