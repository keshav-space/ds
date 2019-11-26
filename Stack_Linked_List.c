#include <stdio.h>
#include <stdlib.h>
#define ERROR 404

typedef struct node{
    int num;
    struct node * next;
} node;

void init(node ** top){
    *top=NULL;
}

// fail code is FALSE
int isEmpty(node * top){
    return (top==NULL);
}

// fail code is 1 ie. Overflow
int push(node ** top, int n){
    node *temp=(node *) malloc(sizeof (node) );
    if(temp){
        temp->num=n;
        temp->next=*top;
        *top=temp;
        return 0;
    }
    return ERROR;
}

// fail code is 1 ie. Underflow
int pop(node ** top){
    if(!isEmpty(*top)){
        node *temp=*top;
        *top=(*top)->next;
        int n=temp->num;
        free(temp);
        return n;
    }
    return ERROR;
}

// fail code id 404 i.e Underflow
int peek(node * top){
    if(!isEmpty(top))
        return (top->num);
    return ERROR;    
}

int main(){
    node * top;
    init(&top);
    int x=1,n;
    while(x){
        printf("\n\n1.Push\n2.Pop\n3.Peek\n0.Exit\n");
        scanf("%d",&x);
        if(x==1){
            printf("\nEnter the element to push: ");
            scanf("%d",&n);
            if(push(&top,n)==ERROR)
                printf("\nOverlfow!");
        }
        else if(x==2){
            n=pop(&top);
            if(n==ERROR)
                printf("\nUnderlfow");
            else 
                printf("\n poped %d",n);
        }
        else if(x==3){
            n=peek(top);
            if(n==ERROR)
                printf("\nUnderlfow");

            else
                printf("\nPeeked %d: ",n);
            
        }
    }
    return 0;
}