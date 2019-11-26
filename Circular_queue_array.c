#include<stdio.h>
#define Max 100
#define ERROR 4040404
typedef enum {false,true} bool;

typedef struct queue{
    int data[Max];
    int front,rear;
} queue;

void initqueue(queue * s){
    s->front = s->rear = -1;
}

bool isempty(queue s){
    return(s.rear == -1);
}

bool isfull(queue s){
    return((s.rear == Max-1 && s.front == 0) || (s.rear+1 == s.front));
}

bool enqueue(queue *s,int n){
    int i;
    if(isfull(*s)){
        printf("Queue is full");
        return false;
    }

    else {
        if(isempty(*s))
            s->front = s->rear = 0;
        else if(s->rear == Max-1)
            s->rear = 0;
        else 
            s->rear++;    
        }
    s->data[s->rear] = n;
    return true;         
}

int dequeue(queue *s){
    int temp;
    if(!isempty(*s)){
        temp = s->data[s->front];
        if(s->front == s->rear)
            initqueue(s);

        else if(s->front == Max-1)
            s->front = 0;
        else
            s->front++;    
        return(temp);
    }
    return ERROR;        
}

int peekqueue(queue s){
    return(s.data[s.front]);
}
