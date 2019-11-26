#include<stdio.h>
#define Max 100
#define ERROR 4040404
typedef enum {false,true} bool;

typedef struct queue{
    int data[Max];
    int front,rear;
} queue;

void initqueue(queue * s){
    s->front=s->rear=-1;
}

bool isempty(queue s){
    return(s.rear==-1);
}

bool isfull(queue s){
    return(s.rear==Max-1);
}

bool enqueue(queue *s,int n){
    int i;
    if(isempty(*s))
        s->front=0;

    else if(isfull(*s)){ 
        if(s->front!=0){ //doing sifting if space is available
            for(i=s->front;i<=s->rear;i++)
                s->data[i-s->front]=s->data[i];
            s->rear=s->rear - s->front;
            s->front=0;
        }
        else //if no space available
            return false;
    }
    
    s->data[++s->rear]=n;
    return true;         
}

int dequeue(queue *s){

    if(!isempty(*s)){
        int temp=s->data[s->front];
        if(s->front==s->rear)
            initqueue(s);
        else
            (s->front)++;    
        return(temp);
    }
    return ERROR;        
}

int peekqueue(queue s){
    return(s.data[s.front]);
}
