#include<stdio.h>
#include<stdlib.h>

typedef struct binary{
    int data;
    struct binary *left,*right;
}binary;

typedef enum{flase,true} bool;

void init(binary**);
bool insert(binary**, int);
bool preoder(binary*);
bool inorder(binary*);
bool postorder(binary*);
int height(binary*);
void mirrorimage(binary**);
int totalnode(binary*);
int leafnode(binary*);
int internalNode(binary*);
binary *smallNode(binary*);
binary *largeNode(binary*);
void removetree(binary**);
void searchnode(binary *,binary **,binary **,bool *,int);
bool deleteNode(binary **,int); //return true for sucessful delete else return false


void init(binary **root){
    *root = NULL;
}

bool insert(binary ** root,int n){
    if(*root == NULL){
        *root=(binary *) malloc(sizeof(binary));
        if(*root==NULL)
            return flase; // malloc failure 
        (*root)->left=(*root)->right=NULL;
        (*root)->data=n;
    }
    else if((*root)->data <= n)
        insert(&(*root)->right,n);
    else 
        insert(&(*root)->left,n);
    return true;    
}

bool preoder(binary *root){
    if(root){
        printf("%d, ",root->data);
        preoder(root->left);
        preoder(root->right);
    }
    else 
        return flase;
    return true;    
}

bool inorder(binary *root){
    if(root){
        inorder(root->left);
        printf("%d, ",root->data);
        inorder(root->right);
    }
    else 
        return flase;
    return true;
}

bool postorder(binary *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d, ",root->data);
    }
    else 
        return flase;
    return true;
}

int height(binary *root){
    if(!root)
        return 0;
    return(1+ ( (height(root->right) > height(root->left)) ? height(root->right) : height(root->left) ) );       
}

void mirrorimage(binary **root){
    if(*root){
        mirrorimage(&(*root)->left);
        mirrorimage(&(*root)->right);

        binary *temp = (*root)->left;
        (*root)->left = (*root)->right;
        (*root)->right = temp;
    }
}

int totalnode(binary *root){
    if(!root)
        return 0;
    return(totalnode(root->right) + totalnode(root->left) + 1);    
}

int leafnode(binary *root){
    if(!root)
        return 0;
    else if( root->right==NULL && root->left==NULL )
        return 1;
    return(leafnode(root->right) + leafnode(root->left));      
}

int internalNode(binary *root){
    if((root==NULL) || (root->left == NULL && root->right == NULL))
        return 0;
    return(internalNode(root->left)+internalNode(root->right)+1);    
}

binary *smallNode(binary *root){
    if(root==NULL || root->left==NULL)
        return root;
    return smallNode(root->left);    
}

binary *largeNode(binary *root){
    if(root==NULL || root->right==NULL)
        return root;
    return largeNode(root->right);    
}

void removetree(binary **root){
    if(*root!=NULL){
        removetree(&(*root)->left);
        removetree(&(*root)->right);
        free(*root);
    }
}

void searchnode(binary *root,binary **cur,binary **pare,bool *found,int n){
    *pare=NULL;
    *cur=root;
    *found=flase;
    while(*cur){
        if((*cur)->data==n){
            *found=true;
            break;
        }
        else if((*cur)->data > n){
            *pare=*cur;
            (*cur)=(*cur)-> left;
        }
        else{
            *pare=*cur;
            (*cur)=(*cur)->right;
        }
    }
}

/*
void deletenode(binary **root,int n){
    binary *cur,*pare;
    bool found;
    searchnode(*root,&cur,&pare,&found,n);
    if(!found){
        printf("Eement not found");
        return;
    }
    if(cur->left==NULL && cur->right==NULL){ // if it's leaf node
        if(cur==*root) //if it's root node
            *root=NULL;

        else if(pare->left==cur)
            pare->left=NULL;

        else
            pare->right=NULL;
        free(cur);    

        return;
    }

    else if(cur->left==NULL && cur->right!=NULL){ //if left node is null and right is not
        if(cur==*root)
            *root=cur->right;

        else if(pare->right==cur)
            pare->right=cur->right;

        else
            pare->left=cur->right;

        free(cur);

        return;            
    }

    else if(cur->left!=NULL && cur->right==NULL){ //if left node is not null and right is null
        if(cur==*root)
            *root=cur->left;

        else if(pare->right==cur)
            pare->right=cur->left;

        else
            pare->left=cur->left;

        free(cur);

        return;            
    }

    else if(cur->left!=NULL && cur->right!=NULL){ //if none of the node is null
        if(cur==*root)
            *root=cur->right;

        else if(pare->right==cur)
            pare->right=cur->right;

        else
            pare->left=cur->right;

        free(cur);

        return;            
    }

} */

bool deleteNode(binary **root,int n){
    if(*root==NULL)
        return flase;

    else if(n> (*root)->data)
        deleteNode(&(*root)->right,n);

    else if(n<(*root)->data)
        deleteNode(&(*root)->left,n);

    else if(n==(*root)->data){
        //case 1: leaf node
        if((*root)->left==NULL && (*root)->right==NULL){
            free(*root);
            *root=NULL;
        }

        //case 2: one child
        else if((*root)->left!=NULL && (*root)->right==NULL){
            binary *temp=*root;
            *root=(*root)->left;
            free(temp);
        }
        else if((*root)->left==NULL && (*root)->right!=NULL){
            binary *temp=*root;
            *root=(*root)->right;
            free(temp);
        }

        //case 3: 2 child
        else{
            binary *temp=largeNode((*root)->left); // do max of left side or min of right side
            (*root)->data=temp->data;
            deleteNode(&(*root)->left,temp->data);
        }
        return true;
    }

    return flase;            
}

int main(){
    int n=1,input;
    binary *tree,*temp1,*cur;
    bool found;
    init(&tree);
    while(n){
        printf("\n0. Exit\n1. Insert\n2. Preorder.\n3. Inorder.\n4. Postorder\n5. Height\n6. Mirror Image\n7. Total Node\n8. Leaf Node\n9. Inner Node\n10. Small Node\n11. Large Node\n12. Search \n13.Remove Tree\n14. Delete a Node\n");
        printf("Enter the choice: ");
        scanf("%d",&n);
        if(n==1){
            printf("Enter the no to be inserted: ");
            scanf("%d",&input);
            if(!insert(&tree,input))
                printf("\nInsertion failed\n");
        }
        else if(n==2){
            if(!preoder(tree))
                printf("\nTree is empty\n");
        }
        else if(n==3){
            if(!inorder(tree))
                printf("\nTree is empty\n");
        }
        else if(n==4){
            if(!postorder(tree))
                printf("\nTree is empty\n");
        }
        else if(n==6){
            mirrorimage(&tree);
        }
        else if(n==5){
            printf("\nThe height of tree is %d .",(height(tree)));
        }
        else if(n==7){
            printf("\nThe total node in tree is %d .",(totalnode(tree)));
        }
        else if(n==8){
            printf("\nThe total leaf node in tree is %d .",(leafnode(tree)));
        }
        else if(n==9){
            printf("\nThe total inner node in tree is %d .",(internalNode(tree)));
        }
        else if(n==10){
            printf("\nThe smallest node in tree is %d .",(smallNode(tree)->data));
        }
        else if(n==11){
            printf("\nThe largest node in tree is %d .",(largeNode(tree)->data));
        }
        else if(n==12){
            printf("\nEnter the no to search in tree: ");
            scanf("%d",&input);
            searchnode(tree,&cur,&temp1,&found,input);
            if(found)
                printf("\nFund at the node address %p",cur);
            else
                printf("\nNot found");    
        }
        else if(n==13){
            removetree(&tree);
        }
        else if(n==14){
            printf("\nEnter the value to be deleated: ");
            scanf("%d",&input);
            if(!deleteNode(&tree,input))
                printf("\nThe node is not present in tree.");
        } 
    }
}