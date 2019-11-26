#include <stdio.h>
#include <stdlib.h>

typedef struct avl{
    int data,ht;
    struct avl *l,*r;
} node;

int max(int a,int b){
    return a>b?a:b;
}

int height(node *aah){
    if(aah==NULL)
        return 0;
    return aah->ht;    
}

node *create(int data){
    node *n=(node *) malloc(sizeof(node));
    n->data = data;
    n->l=n->r=NULL;
    n->ht = 1;
    return n;
}

node *rr(node *y){
    node *x = y->l;
    node *t2 = x->r;

    //Rotation
    x->r = y;
    y->l = t2;

    //height 
    y->ht = max(height(y->l), height(y->r)) +1;
    x->ht = max(height(x->l), height(x->r)) +1;

    return x;
}

node *lr(node *x){
	node *y = x->r;
	node *T2 = y->l;
	
	//rotation
	y->l = x;
	x->r = T2;
	
	//Height update
	x->ht = max(height(x->l), height(x->r))+1;
	y->ht = max(height(y->l), height(y->r))+1;
	
	return y;
}

int getbalance(node *n){
    if(n==NULL)
        return 0;
    return height(n->l) - height(n->r);    
}

node *insert(node *n,int data){
    if(n==NULL)
        return create(data);
    if(data < n->data)
        n->l = insert(n->l, data);
    else if(data > n->data)
        n->r = insert(n->r, data);
    else 
        return n;
    // height update
    n->ht = 1+ max(height(n->l),height(n->r));

    int bal = getbalance(n);

    //LLC  left overload doing right rotation 
    if(bal >1 && (n->l)!=NULL && data < (n->l)->data )
        return rr(n);
    //RRC right overload doing left rotation
    if(bal > -1 && (n->r)!=NULL && data > (n->r)->data)
        return lr(n);       
    // LRC doing left rotation followed by right rotation 
    if(bal >1 && (n->l)!=NULL && data > (n->l)->data){
        n->l = lr(n->l);
        return rr(n);
    }
    //RLC doing right rotation followed by left rotation 
    if(bal < -1 && (n->r)!=NULL && data < (n->r)->data){
        n->r = rr(n->r);
        return lr(n);
    }    
    return n;
}

void preorder(node *n){
    if(n!=NULL){
        printf("%d,",n->data);
        preorder(n->l);
        preorder(n->r);
    }
}

void inorder(node *n){
    if(n!=NULL){
        inorder(n->l);
        printf("%d,",n->data);
        inorder(n->r);
    }
}

int main(){
    node *root = NULL;
    int n,i;
    for(i=0;i<10;i++){
        scanf("%d",&n);
        root = insert(root,n);
        preorder(root);
        printf("\n");
        inorder(root);
        printf("\n");
    }
}