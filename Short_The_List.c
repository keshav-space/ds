#include <stdio.h>
#include <stdlib.h>
#define ERROR 404040

typedef struct node{
	int num;
	struct node *next;
} node;


int show(node *p){
    if(p){
        printf("\n|%p  | %d | %p|\n▼▼▼▼▼▼",p,(p->num),(p->next));
        show(p->next);
    }
    else
        return ERROR;
    return 1; //sucess code
}

void swapNode(node * n1,node * n2,node ** pre1,node ** pre2){
	// swamp the their pointer ( This must be done at First to  avoid error in case when prev of 2 and curent1 is same :) 
    node * temp;
	temp=*pre1;
	*pre1=*pre2;
    *pre2=temp;

	// swap the value of corrosponding next 
	temp=(n1)->next;
	(n1)->next=(n2)->next;
	(n2)->next=temp;
}

void shortThe(node ** head){
	node * cur2,* cur1, *small,*pre1,*pre2,*small_prev;
	for(cur1=*head,pre1=NULL;cur1;pre1=cur1,cur1=cur1->next){
		small=NULL;
		for(cur2=cur1->next,pre2=cur1;cur2;pre2=cur2,cur2=cur2->next){
			if( ((cur2->num)<(cur1->num) && !small) || (small && (cur2->num)<(small->num)) ){
				small = cur2;
                small_prev=pre2;
            }
		}
		if(small){
            if(pre1==NULL){// in case when the swap is done for the first positon element
                swapNode(cur1,small,&(*head),&(small_prev->next));
                cur1=small; //reset the pointer to correct positon bcz the current node is swaped
            }
            else{
                swapNode(cur1,small,&(pre1->next),&(small_prev->next));
                cur1=small; //reset the pointer to correct positon bcz the current node is swaped
            }    
        }	
	}
}

void init(node **p){
    *p=NULL;
}

int insert(node **p,int n){
    node *temp,*pre,*cur;
    temp=(node *)malloc(sizeof(node));
    if(temp){
        temp->num=n;
        for(pre=NULL,cur=*p;cur;cur=cur->next)
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


int main(){
    node * head;
    init(&head);
    int x=1,n;
    while(x){
        printf("\n\n1.Insert\n2.Delet\n3.Show\n4.Short\n0.Exit\n");
        scanf("%d",&x);
        if(x==1){
            printf("\nEnter the element to insert: ");
            scanf("%d",&n);
            if(insert(&head,n)==ERROR)
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
		shortThe(&head);
	}
    }
    return 0;
}