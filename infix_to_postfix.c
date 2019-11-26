#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR 404
#define Max 100
typedef enum{false=0,true} bool;

typedef struct node{
    char c;
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
int push(node ** top, char n){
    node *temp=(node *) malloc(sizeof (node) );
    if(temp){
        temp->c=n;
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
        char n=temp->c;
        free(temp);
        return 1;
    }
    return ERROR;
}

// fail code id 404 i.e Underflow
char peek(node * top){
    if(!isEmpty(top))
        return (top->c);
    return '@';    
}


bool isopening(char c){
    if(c=='(' || c=='{'||c=='[')
        return true;
    return false;    
}

bool iscloasing(char c){
    if(c==')' || c=='}'||c==']')
        return true;
    return false;    
}

bool isoperand(char c){
    if((c >= 'a' && c<='z') || (c >= 'A' && c<='Z') || (c >= '0' && c <= '9'))
        return true;
    return false;    
}

bool isoperator(char c){
	if(c == '+' || c == '-' || c == '*' || c == '/' || c== '^')
		return true;

	return false;    
}

bool isRightAssociative(char operand){
	if(operand == '^') return true;
	return false;
}

//operator precedence. 
int weight(char operand){
	int wt = -1; 
	switch(operand){
	case '+':
	case '-':wt = 1;
             break;
	case '*':
	case '/':wt = 2;
             break;
	case '^':wt = 3;
	}
	return wt;
}

// If operators have equal precedence, return true if they are left associative. 
// return false, if right associative. 
// if operator is left-associative, left one should be given priority. 
bool higherprecedence(char opInSatack, char currentOp){
	int opInSatackWeight = weight(opInSatack);
	int currentOpWeight = weight(currentOp);

	if(opInSatackWeight == currentOpWeight){
		if(isRightAssociative(opInSatack))
            return false;
		else 
            return true;
	}
	return (opInSatackWeight > currentOpWeight) ?  true: false;
}

char* infixtopost(char *s){
    char *sol=(char*) malloc(sizeof(char)* strlen(s));
    int k=0;
    node *stack_head;
    init(&stack_head);

    for(int i=0;i<=strlen(s);i++){
        if(s[i] == ' ' || s[i] == ',')
            continue;
        
        else if(isoperand(s[i]))
            sol[k++]=s[i];

        else if(isoperator(s[i])){
            while(!isEmpty(stack_head) && !isopening(peek(stack_head)) && higherprecedence(peek(stack_head),s[i]) ){
                sol[k++] = peek(stack_head);
                pop(&stack_head);
            }
            push(&stack_head,s[i]);
        }

        else if (isopening(s[i])){
            push(&stack_head,s[i]);
        }

        else if(iscloasing(s[i])){
            while(!isEmpty(stack_head) && !isopening(peek(stack_head)) ){
                sol[k++] = peek(stack_head);
                pop(&stack_head);
            }
            pop(&stack_head); // to pop opening parenthasis           
        }    
    }

    while(!isEmpty(stack_head) ){
        sol[k++] = peek(stack_head);
        pop(&stack_head);
    }
    sol[k++]='\0';
    return sol; 
}

int main(){
    char *s=infixtopost("w*(r-t/y)");
    printf("%s",s);
    return 0;
}