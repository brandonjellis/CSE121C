/*
Brandon Ellis
01/08/2022
A collection of various simple commands used to practice basic c syntax for the CSE121C course. 
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int i = 42;
    short s = 7;
    long l = 14624862;
    char c = 'A';
    float userFloat = 0;

    printf("The integer has the value: %d and uses %ld Bytes.\n",i,sizeof(i));
    printf("The short has the value %d and uses %ld Bytes.\n",s,sizeof(s));
    printf("The long has the value %ld and uses %ld Bytes.\n",l,sizeof(l));
    printf("The character has the value %c and uses %ld Bytes.\n",c,sizeof(c));

    printf("Enter a number:");
    scanf("%f",&userFloat);

    printf("Standard: %f\nScientific: %e\nShortened: %g\n",userFloat,userFloat,userFloat);

    char name[32];
    printf("What is your name?");
    scanf("%s",name);
    printf("Your name is %s\n",name);

    typedef struct profile{
        char name[16];
        unsigned int age;
        float balance;
    } profile_t;

    profile_t p = {"Smith", 36, 4526.32};

    printf("structure first part = %s has the size: %ld\n",p.name,sizeof(p.name));
    printf("structure second part = %d has the size: %ld\n",p.age,sizeof(p.age));
    printf("structure third part = %f has the size: %ld\n",p.balance,sizeof(p.balance));

    printf("the size of the entire structure is: %ld",sizeof(p));

    return EXIT_SUCCESS;

};