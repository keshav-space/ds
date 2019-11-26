#include<stdio.h>
#include<stdlib.h>
#include "Queue_Array.c"
#include "Stack_Array.c"

#define INFINITE 100000

typedef struct {
    int n;
    char *v;
    int ** weight;
} graph;

void inputGraph(graph * gr){

    int i,j,w;
    char ans;
    printf("\nEnter the total no of vertex ");
    scanf("%d",&gr->n);
    gr->v=(char *)malloc(sizeof(gr->n));

    for(i=0;i<gr->n;i++)
        gr->v[i]='A'+i;

    gr->weight=(int **)malloc((gr->n)*sizeof(int *));

    for(i=0;i<gr->n;i++)
        for(j=0;j<gr->n;j++)
           gr->weight[i]=(int *)malloc(sizeof(int)*gr->n);
/*
    for(i=0;i<gr->n;i++)
        for(j=0;j<gr->n;j++){
            printf("\nIs there edge between %c and %c? :(Y/N) ",'A'+i,'A'+j);
            getchar();
            scanf("%c",&ans);
            if(ans=='Y'||ans=='y'){
                printf("\nEnter the weight: ");
                scanf("%d",&(gr->weight[i][j]));
            }
            else {
                gr->weight[i][j]=INFINITE;
            }
        } 
        */ 
gr->weight[0][0]=0;
gr->weight[0][1]=5;
gr->weight[0][2]=5;
gr->weight[0][3]=INFINITE;
gr->weight[0][4]=INFINITE;
gr->weight[1][0]=5;
gr->weight[1][1]=0;
gr->weight[1][2]=INFINITE;
gr->weight[1][3]=5;
gr->weight[1][4]=5;
gr->weight[2][0]=5;
gr->weight[2][1]=INFINITE;
gr->weight[2][2]=0;
gr->weight[2][3]=INFINITE;
gr->weight[2][4]=INFINITE;
gr->weight[3][0]=INFINITE;
gr->weight[3][1]=5;
gr->weight[3][2]=INFINITE;
gr->weight[3][3]=0;
gr->weight[3][4]=INFINITE;
gr->weight[4][0]=INFINITE;
gr->weight[4][1]=5;
gr->weight[4][2]=INFINITE;
gr->weight[4][3]=INFINITE;
gr->weight[4][4]=0;    

printf("asfSADFSAD");
}

void dfs(graph gr, int num){
    
    int i,p,start=0;
    stack stk;
    initstack(&stk);
    int *visited=(int *)malloc(sizeof(int)*gr.n);
    for(i=0;i<gr.n;i++)
        visited[i]=0;

    visited[num]=1;
    push(&stk,num);
    printf("\n visited: %c",'A'+num);
    while(stk.top!=-1){
        if(start==1)
            p=pop(&stk);
        for(i=0;i<gr.n;i++)
            if(gr.weight[p][i]!=INFINITE && gr.weight[p][i]!=0 && visited[i]==0){
                push(&stk,i);
                visited[i]=1;
                p=i;
                printf("\n visited: %c",'A'+i);                
            }
        start=1;           
    }
    free(visited);
}

void bfs(graph gr, int num){
    
    int i,p,start=0;
    queue qu;
    initqueue(&qu);
    int *visited=(int *)malloc(sizeof(int)*gr.n);
    for(i=0;i<gr.n;i++)
        visited[i]=0;

    visited[num]=1;
    enqueue(&qu,num);
    while(qu.front!=-1){
        p=dequeue(&qu);
        printf("\n visited: %c",'A'+p);
        for(i=0;i<gr.n;i++)
            if(gr.weight[p][i]!=INFINITE && gr.weight[p][i]!=0 && visited[i]==0){
                enqueue(&qu,i);
                visited[i]=1;                
            }
    }
    free(visited);
}


int main(){
    graph gh;
    inputGraph(&gh);
    bfs(gh,0);
}