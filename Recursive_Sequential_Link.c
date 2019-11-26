// Link list for sequential insertion using recuression
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

int insertSequential(node **p,int n){
    if(*p==NULL || (*p)->next==NULL){
       node * temp=(node * ) malloc(sizeof(node));
       if(temp){
            temp->next=NULL;
            temp->num=n;
            if(*p==NULL)
                *p=temp;
            else 
                (*p)->next=temp;
       }
       else 
            return ERROR; // malloc failure
    }
    else 
        insertSequential(&(*p)->next,n);
    return 1;
}

int rmRecu(node **p,int n){
    if((*p)==NULL)
        return ERROR; //list is empty

    else if((*p)->num ==n){ //if not empty and found element
        node *temp=*p;
        *p=(*p)->next;
        free(temp);
    }

    else
        rmRecu(&(*p)->next,n);
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
    if(p==NULL)
        return 0;
    else 
        return(countnode(p->next)+1);    
}

void reverse(node **p){
    node *pre,*cur,*t;
    for(cur=*p,pre=NULL;cur;cur=t){
        t=cur->next;
        cur->next=pre;
        pre=cur;
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
            if(insertSequential(&head,n)==ERROR)
                printf("\nOverlfow");
        }
        else if(x==2){
            printf("\nEnter the element to delete: ");
            scanf("%d",&n);
            n=rmRecu(&head,n);
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