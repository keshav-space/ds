#include<stdio.h>
#define Max 100
#define ERROR 4040404

typedef enum {false=0,ture} bool;

typedef struct stack{
    int a[Max];
    int top;
} stack;

void initstack(stack *s){
    s->top=-1;
}

// fail code is 0
int notEmpty(int top){
    if(top==-1)
        return 0;
    return 1;    
}

// fail code is 0
int notOverflow(int top){
    if(top==Max-1)
        return 0;
    return 1;
}

// fail code is ERROR
int push(stack *s,int n){
    if(notOverflow(s->top))
        s->a[++s->top]=n;
    else
        return 0;
    return ERROR;    
}

// fail code is Error
int pop(stack * s){
    if(notEmpty(s->top))
        return (s->a[(s->top)--]);
    else
        return ERROR;
}

// fail code is ERROR
int peekstack(stack s){
    if(notEmpty(s.top))
        return s.a[s.top];
    return ERROR;    
}
/*
int main(){
    stack s;
    int n=1,x;
    initstack(&s);
    while (n){
        printf("\n0.Exit\n1.Push\n2.Pop\n3.Peek\n");
        scanf("%d",&n);
        if(n==1){
            printf("\nEnter the no to insert: ");
            scanf("%d",&x);
            if(push(&s,x)==ERROR)
                printf("\nError Overflow!");
        }
        else if(n==2){
            x=pop(&s);
            if(x==ERROR)
                printf("\nError Underflow!");
            else
                printf("\n%d Removed",x);    
        }
        else if(n==3){
            x=peek(s);
            if(x==ERROR)
                printf("\nError Underfolow!");
            else 
                printf("\n%d",x);
        }
    }
    return 0;
}
*/