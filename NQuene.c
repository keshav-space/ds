#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 8
 

typedef struct 
{
 int *C;
 int no_queen;
}BOARD;

/*
===================================================
C[i] = column index of the ith Queen.
position of ith Queen : (i,C[i])
===================================================
*/


void initialisation(BOARD *, int );
void display_board(BOARD , int, int * );
int is_safe(BOARD , int , int );
void n_queen(BOARD * ,int, int, int * ); 
/*
===================================================
(x , y): coordinates of the new Queen.
int is_safe(BOARD B, int x, int y): To determine whether a Queen at (x, y) cell is safe.
Information in Hand: Column position of all the queens corresponding to 
row 0 to row (x-1) are known.
===================================================
*/

void initialisation(BOARD *B, int n)
{
  int i;
  B->no_queen=n;
  B->C=(int *)malloc(sizeof(int)*(n+1));
  for(i=1;i<=n;i++)
       B->C[i]=-1;
}

void display_board(BOARD B, int n, int *a_sol_no)
/*Displaying the Solution or Board Configuration.*/
{
  int i,j;
  printf("\n\n Solution %d ", ++(*a_sol_no));
  for(i=1;i<=n;i++)
  {
     printf("\n");
     for(j=1;j<=n;j++)
        if(B.C[i]==j)
          printf(" Q"); 
        else
          printf(" X");
   }  
}

int is_safe(BOARD B, int x, int y)
{
  int i;
  for(i=1;i<x;i++)
      if (B.C[i]==y || abs(x-i)==abs(y-B.C[i]))
            return 0;
  return 1; 
}

void n_queen(BOARD *B, int k, int n, int *a_sol_no)
/* 
===============================================
C[i] = column index of the ith Queen.
Position of ith Queen : (i, C[i])
k = index of the current Queen to be inserted at k th row. 
n = total no. of Queen to be placed.
===============================================
*/
{
  int j;
  for(j=1;j<=n;j++)
        if(is_safe(*B, k, j)) /* Is kth Queen at kth row is safe at jth column. */
          {
              B->C[k]=j; /* Place the kth Queen (at kth row) at jth column. */
             if(k==n) /* All the n Queens are safely placed.*/
                   display_board(*B, n, a_sol_no); /*Displaying the solution.*/
             else
                   n_queen(B,k+1,n, a_sol_no); /* Place the (k+1)th Queen. */
          } 
}


 
int main()
{
 BOARD *p;
 int sol_no=0;
 p=(BOARD *)malloc(sizeof(BOARD));
 initialisation(p,8);
 n_queen(p,1,8,&sol_no);
 return 0;
}
