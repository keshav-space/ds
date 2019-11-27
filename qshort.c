#include<stdio.h>
void inputI(int a[],int n){
    for(int *i=a;i<(a+n);i++)
        scanf("%d",i);
}
void printI(int a[],int n){
    for(int *i=a;i<(a+n);i++)
        printf("%d ",*i);
    printf("\n");    
}
int partiton(int  a[],int start,int end){
    printI(a,end);
    int pindex=start,i,temp;
    for(i=start;i<end;i++){
        if(a[i]<a[end]){
            temp=a[i];
            a[i]=a[pindex];
            a[pindex]=temp;
            pindex++;
        }
    }
    temp=a[pindex];
    a[pindex]=a[end];
    a[end]=temp;
    printI(a,end); 
    return pindex;   
}

void qshort(int a[],int start,int end){
    if(start<end){
        int pivot=partiton(a,start,end);
        qshort(a,start,pivot-1);
        qshort(a,pivot+1,end);
    }
}

int main(){
    int a[20], n;
    scanf("%d",&n);
    inputI(a,n);
    //printI(a,n);
    printf("\n");
    qshort(a,0,n);
    printI(a,n);
}