#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

/* Logic for Lower Traingular Matrix storage in rowmajor order
Consider a matrix 
[ 1 2 3 4 ]
| 0 5 6 7 |
| 0 0 8 9 |
[ 0 0 0 10]

here A[1][2] means 1 row 2 column where generalized format shows i as row and j as column
So all zero elements are in position where i<j => M[i,j]=0 where i<j
and distinct elements are in position where i>=j => M[i,j]= non zero where i>=j

total non zero elements in matrix = 4(first row) + 3(second row) + 2(3rd row) + 1(4th row) = 1+2+3+4 => n(n+1)/2
total elements in matrix = n^2
total zero elements in matrix = n^2-n(n+1)/2 = n(n-1)/2

To store nonzero elements in array we need n(n+1)/2 elements space
[A11,A12,A13,A14,A22,A23,A24,A33,A34,A44] Array
  0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 Index

  To access A34 => Aij = (1 row + 2 nd row )+ 1
  A23 = 1 row(4) +  1
  A44 = 1 row(4) + 2nd row(3) + 3rd row(2) + 1

  Aij= (n+n-1+n-2....n-(i-2))+j-i
  Aij = [(i-1)n-(i-2)(i-1)/2]+j-i
*/


struct Matrix 
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if(i<=j)
    {
        m->A[(i-1)*m->n-(i-1)*(i-2)/2+j-i]=x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if(i<=j)
        return m.A[(i-1)*m.n-(i-1)*(i-2)/2+j-i];
    else
        return 0;
}

void Display(struct Matrix m)
{
    int i,j;

    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i<=j)
                printf("%d ",m.A[(i-1)*m.n-(i-1)*(i-2)/2+j-i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}


int main()
{
    struct Matrix m;
    int i,j,x;

    printf("Enter the dimension of matrix ");
    scanf("%d",&m.n);
    m.A=(int *)malloc(m.n*(m.n-1)/2*sizeof(int));

    printf("Enter Elements of matrix ");
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i<=j)
            {
                scanf("%d",&x);
                Set(&m,i,j,x);
            }
        }
    }
    printf("\n\n");
    printf("%d \n",Get(m,2,1));
    Display(m);

  return 0;
}