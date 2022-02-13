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
char title[32]; 
time_t checkout;
struct book* next;
};

struct acct{
unsigned int acctNum;
char name[32];
struct book* booklist;
struct book* bookend;
struct acct* next;
};

void createAccount(struct acct** first, struct acct** newest);
void checkBook(struct acct* acct);
void writeAccount(struct acct* a);
void writeBook(struct book* b);
void printAccount(struct acct* a);
void printBook(struct book* b);
void showAccount(struct acct* acct);
struct acct* findAccount(struct acct* first);
struct book* newestBook(struct book* first);
struct acct* newestAcct(struct acct* first);
void deleteAcct(struct acct* first);
void listAccounts(struct acct* list);

int main(){

    struct acct* firstAcct = NULL; 
    struct acct* selAcct = NULL;
    struct acct* newestAcct = NULL;
    short loop = 1;
    short userChoice = 0;

    printf("Library Management System V1.0:\n");
    while(loop == 1){
        printf("MAIN MENU:\n");
        printf("[1] CREATE ACCOUNT\n[2] EDIT ACCOUNT\n[3] DELETE ACCOUNT\n[4] LOOKUP ACCOUNT\n[5] CHECKOUT BOOK\n[6] RETURN BOOK\n[7] LIST ACCOUNTS\n\n[0] EXIT PROGRAM\n\n");
        scanf("%d",&userChoice);

        switch (userChoice){
            case 1:
            printf("newest: %p\nnewestADD: %p\n",newestAcct,&newestAcct);
            createAccount(&firstAcct, &newestAcct);
            printf("newest: %p\nnewestNext: %p\nfirst: %p\nfirstNext: %p\n",newestAcct,newestAcct->next,firstAcct,firstAcct->next);
            break;

            case 2:
            selAcct = findAccount(firstAcct);
            if(selAcct != NULL){
                writeAccount(selAcct);
                printf("Account edited.\n");
            }
            break;

            case 3:
            break;

            case 4:
            selAcct = findAccount(firstAcct);
            if(selAcct != NULL){
                showAccount(selAcct);
            }
            break;

            case 5:
            selAcct = findAccount(firstAcct);
            if(selAcct != NULL){
                checkBook(selAcct);
            }
            break;

            case 6:
            break;

            case 7:
            listAccounts(firstAcct);
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

void createAccount(struct acct** first, struct acct** recent){
    struct acct* new = NULL;
    new = malloc(sizeof(struct acct));
    new->next = NULL;
    new->booklist = NULL;
    new->bookend = NULL;
    writeAccount(new);
    if(*first == NULL){
        *first = new;
        *recent = new;
    }
    else{
        printf("recent: %p\n*recent %p\n",recent,*recent);
        (*recent)->next = new;
        *recent = new;
    }
    printf("Account Created!\n");
}

void checkBook(struct acct* acct){
    struct book* newBook = malloc(sizeof(struct book));
    newBook->next = NULL;
    writeBook(newBook);
    if (acct->booklist == NULL){
        acct->booklist = newBook;
        acct->bookend = newBook;
    }
    else{
        acct->bookend->next = newBook;
        acct->bookend = newBook;
    }
}


void writeAccount(struct acct* a){
    printf("\n");
    printf("What is the account number?: ");
    scanf("%d", &a->acctNum);
    printf("What is the account name?: ");
    scanf("%s", a->name);
    printf("\n");
}

void writeBook(struct book* b){
    printf("\n");
    printf("What is the book title?: ");
    scanf("%s", b->title);
    printf("What is the book code?: ");
    scanf("%d", &b->idNum);
    b->checkout = time(NULL);
}

void printAccount(struct acct* a){
    printf("#%d NAME: %s\n",a->acctNum, a->name);
    printf("%x\n",a->next);
}

void printBook(struct book* b){
    printf("TITLE: %s , ID:%d, CHECKED OUT: %s", b->title, b->idNum, ctime(&(b->checkout)));
}

void showAccount(struct acct* acct){
    struct acct* a = acct;
    if(a != NULL){
        printAccount(a);
        printf("BOOKS ON FILE:\n");
        struct book* b = a->booklist;
        while(b){
            printBook(b);
            b = b->next;
        }
        printf("\n");
    }
}

void listAccounts(struct acct* list){
    struct acct* t = list;
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

struct acct* findAccount(struct acct* first){
    int acctKey = 0;
    printf("Enter the account number:\n");
    scanf("%d",&acctKey);
    struct acct* i = first;
    while(i){
        if(i->acctNum == acctKey){
            printf("Account found!\n");
            return i;
        }
        i = i->next;
    }
    printf("Account not found!\n");
    return NULL;
}

void deleteAcct(struct acct* first){

}