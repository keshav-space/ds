#include<stdio.h>
#include<stdlib.h>
#define ERROR 404
typedef struct node{
    int num;
    struct node *next;
} node;

void init(node **p){
    *p=NULL;
}

int insertAss(node **p,int n){
    node *temp,*pre,*cur;
    temp=(node *)malloc(sizeof(node));
    if(temp){
        temp->num=n;
        for(pre=NULL,cur=*p;cur && cur->num<n;cur=cur->next)
            pre=cur;
        if(pre)//if pre is not NULL..current is not the begninnig of the list
            pre->next=temp;
        else
            *p=temp;
        temp->next=cur;           
    }
    else
        return ERROR; //Stack overflow
    return 1;
}
int rm(node **p,int n){
    node *temp,*pre,*cur;
    if(*p){
        for(pre=NULL,cur=*p;cur && !(cur->num==n);cur=cur->next)
            pre=cur;

        if(cur && pre)
            pre->next=cur->next;

        else if(!pre && cur)
            *p=cur->next;

        else
            return -1; //Element not found in the list

        free(cur);    
    }
    else
        return ERROR; //list is empty
    return 1; // deleted sucessfully
}

int show(node *p){
    if(p){
        printf("\n|%d | %p|\n▼▼▼▼▼▼",(p->num),(p->next));
        show(p->next); 
    }
    else
        return ERROR;    
    return 1; //sucess code
}

int countnode(node *p){
    node *cur;
    int i=0;
    for(cur=p;cur;cur=cur->next)
        i++;
    return i;    
}

void reverse(node **p){
    node *pre,*cur,*t;
    for(cur=*p,pre=NULL;cur;cur=t){
        t=cur->next;
        cur->next=pre;
    }
    *p=pre;
}

int main(){
    node * head;
    init(&head);
    int x=1,n;
    while(x){
        printf("\n\n1.Insert\n2.Delet\n3.Show\n4.Count Node\n5. Reverse\n0.Exit\n");
        scanf("%d",&x);
        if(x==1){
            printf("\nEnter the element to insert: ");
            scanf("%d",&n);
            if(insertAss(&head,n)==ERROR)
                printf("\nOverlfow");
        }
        else if(x==2){
            printf("\nEnter the element to delete: ");
            scanf("%d",&n);
            n=rm(&head,n);
            if(n==ERROR)
                printf("\nUnderlfow");
            else if(n==-1)
                printf("\nElement not found in the list");
            else 
                printf("\nElement deleted sucessfully!");        
        }
        else if(x==3){
                if(show(head)==ERROR)
                    printf("\nUnderlfow");
        }
        else if(x==4){
            printf("\nTotal no of node. %d",countnode(head));
        }
        else if(x==5){
            reverse(&head);
        }
    }
    return 0;
}