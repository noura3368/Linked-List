#include <stdio.h>
#include <stdlib.h>
struct node *rest (struct node *L);
void Add(struct node **L, char c);
void Insert(struct node **L, char c);
char first (struct node *L);

struct node {
    char ch;
    struct node *next;
};

int main(void){
struct node *List, *node;
struct node *prt;
struct node *getter;

List=NULL;
Add(&List, 'a');
Add(&List, 'b');
Add(&List, 'c');


printf("first char is: %c \n", first(List));

getter=rest(List);
printf("rest is: ");
for(prt=getter; prt != NULL;){
    printf("%c ", prt->ch);
    prt=prt->next;
}printf("\n");

return 0;
}


void Insert(struct node **L, char c){
    struct node *prt, *node;
    for(prt=*L; prt != NULL;){ //*L address of first elem of linked list which now prt points to 
        //both point to same thing 
        if(prt->ch < c){
            node=malloc(sizeof(struct node));
            node->ch=c;
            node->next=prt;
            *L = node;
        }prt=prt->next; 
    }
}



void Add(struct node **L, char c){

    struct node list, *node;
    node=malloc(sizeof(struct node));
    node->ch=c;
    node->next=*L;
    *L = node;
}

char first (struct node *L){
    if(L != NULL){
        return L->ch;
    }
}
struct node *rest (struct node *L){
    int count=0;
    struct node *prt;
    if(L != NULL){
        for(prt=L; prt != NULL;){
            if(count == 0){
                count++;
            }

            else {
                return prt;
            }
            prt=prt->next;
        }
    }
}