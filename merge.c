#include<stdio.h>
void merge(int instO[],int a[],int b[],int l,int m){
    int i=0,j=0,k=0;
    while(i<l && j<m){
        if(a[i]<b[j]){
            instO[k]=a[i];
            i++;k++;
        }
        else{
            instO[k]=b[j];
            j++;k++;
        }
    }
    while(i<l){
        instO[k]=a[i];
        i++;k++;
    }
    while(j<m){
        instO[k]=b[j];
        j++;k++;
    }
}

int mshort(int a[],int n){
    int mid,i;
    if(n<2)
        return 0;
    mid=n/2;
    int l[mid],r[n-mid];
    for(i=0;i<mid;i++)
        l[i]=a[i];
    int j=0;
    for(i=mid;i<n;i++)
        r[j++]=a[i];
    mshort(l,mid);
    mshort(r,n-mid);
    merge(a,l,r,mid,n-mid);
    return 0;
}

void inputI(int a[],int n){
    for(int *i=a;i<(a+n);i++)
        scanf("%d",i);
}
void printI(int a[],int n){
    for(int *i=a;i<(a+n);i++)
        printf("%d",*i);
}
int main(){
    int a[20], n;
    scanf("%d",&n);
    inputI(a,n);
    printI(a,n);
    printf("\n");
    mshort(a,n);
    printI(a,n);
}