#include<stdio.h>
#include<math.h> // for pow
#include<stdlib.h>
#define Max 100
# define ERROR -999999

typedef struct stackPool{
    float a[Max];
    int top;
} stackPool;

void init(stackPool *stack){
    stack->top = -1;
}

void push(stackPool *stack, float n){
    if(stack->top!=Max)
        stack->a[++(stack->top)]=n;
    else
        printf("Overflow");
}

float pop(stackPool *stack){
    if(stack->top !=-1)
        return stack->a[(stack->top)--];
    printf("Underflow");
    return ERROR;
}

int isOperator(char c){
    return(c=='+' || c=='-' || c=='^' || c=='*' || c=='/');
}

float evaluation(float left ,char operator,float right){
    float result;
    switch(operator){
        case '+':result = left + right;
                break;
        case '-':result = left - right;
                break;
        case '/':result = left/right;
                break;
        case '*':result = left * right;
                break;    
        case '^':result = pow(left,right);
                break;                             
    }
    return result;
}

float postEvaluation(char * exp){
    //char ch[Max];
    int i,j,k;
    char c[10];
    float left,right,t;
    stackPool stack;
    init(&stack);
    for(i=0;exp[i]!='\0';){
        for(k=0;exp[i]!='\0' && exp[i]!=',' && k<10;i++,k++)
            c[k]=exp[i];
        c[k]='\0';  
        if(!isOperator(c[0]))
            push(&stack,atof(c));
        else{
            right=pop(&stack);
            left=pop(&stack);
            printf("doing %f, %c, %f",left,c[0],right);
            push(&stack,evaluation(left,c[0],right));
        }
        if(exp[i])
            i++; //skip delimator ','
    }
    return pop(&stack);
}

int  main(){
    char ch[]="3.0,5.0,7.0,4.0,-,2.0,^,*,+";
    printf("\n %f",postEvaluation(ch));
    return 0;
}