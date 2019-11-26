#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int c,e;
    struct node *next;
} node;

void init(node **aah){
    *aah=NULL;
}

void shortedInsert(node **aah,int c,int e){
    node *t,*i;
    t = (node *)malloc(sizeof(node));
    if(t == NULL)
        return;
    t->c=c;
    t->e=e;

    if(*aah==NULL || (*aah)->e <e){
        t->next = *aah;
        *aah = t;
        return;
    }

    if((*aah)->e == e){
        (*aah)->c += c;
        return;
    }

    i= *aah;
    while(i->next != NULL && (i->next)->e > e){
        i = i->next;

        if(i->next != NULL && (i->next)->e == e){
            (i->next)->c +=c;
            return;
        }
    }
    t->next = i->next;
    i->next = t;
}

void display(node *ah){
    if(ah == NULL){
        printf("1\n");
        return;
    }
    while(ah!=NULL){
        if(ah->c == 1)
            printf("x^%d + ",ah->e);
        else if(ah->e == 0)
            printf("%d + ",ah->c);
        else if(ah->e == 1)
            printf("%dx + ",ah->c);
        else 
            printf("%dx^%d + ",ah->c,ah->e);
        ah=ah->next;            
    }
    printf("\n");
}

void add(node **c,node *a,node *b){
    while(a!=NULL){
        shortedInsert(c,a->c,a->e);
        a=a->next;
    }
    while(b!=NULL){
        shortedInsert(c,b->c,b->e);
        b=b->next;
    }    
}
int main(){
    node *a, *b, *c;
    init(&a);
    init(&b);
    init(&c);
    int co = 1, e, n, i;
    printf("Polynomial 1:\n");
    while(1){
    	printf("Enter coefficient(or 0 to stop): ");
    	scanf("%d", &co);
    	if(co==0)
    		break;
    	printf("Enter exponent: ");
    	scanf("%d", &e);
    	shortedInsert(&a, co, e);
    }
    printf("Polynomial 2:\n");
    while(1){
    	printf("Enter coefficient(or 0 to stop): ");
    	scanf("%d", &co);
    	if(co==0)
    		break;
    	printf("Enter exponent: ");
    	scanf("%d", &e);
    	shortedInsert(&b, co, e);
    }
    add(&c, a, b);

    printf("\n");
    display(a);
    printf("+\t");
    display(b);

    printf("\n");
    display(c);

    printf("\n");
}