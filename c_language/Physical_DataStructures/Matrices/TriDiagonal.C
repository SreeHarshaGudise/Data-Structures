#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
/* 
[a11 a12  0   0   0 ]
|a21 a22 a23  0   0 |
| 0  a32 a33 a34  0 |
| 0   0  a43 a44 a45|
[ 0   0   0  a54 a55]
Diagonal and lower diagonal, upper diagonal are non zero elements

how to find them 
i) if |i-j|<=1 then non zero
ii) if |i-j|<1 then zero elements.

We will only store only non zero elements and how many elements do we require here:
eg: 5x5 matrix from above we can say 
diagonal elements = 5
lower diagonal = 4
upper diagonal = 4, Total = 5+4+4=13
Generalized Formula for storing is: n+n-1+n-1=3n-2;

How to find those indexes in Array:
Fill out lower diagonal matrix elements next diagonal and upper diagonal
a21 a32 a43 a54 a11 a22 a33 a44 a55 a12 a23 a34 a45
 0   1   2   3   4   5   6   7   8   9  10   11  12
  lower diag   |      Diagonal     |  Upper Diag 

  Lower Diagonal if i-j = 1 then index=i-2;
  Diagonal  If i-j=0 then index = n-1+i-1;
  Upper Diagonal if i-j = -1 then index = 2n-1+i-1;

  */




struct Matrix 
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if(i-j==1)
    {
        m->A[i-2]=x;
    }
    else if((i-j)==0)
    {
        m->A[m->n-1+i-1]=x;
    }
    else if((i-j)==-1)
    {
        m->A[2*m->n-1+i-1]=x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if(i-j==1)
        return m.A[i-2];
    else if(i-j==0)
    {
        return m.A[m.n-1+i-1];
    }
    else if(i-j==-1)
    {
        return m.A[2*m.n-1+i-1];
    }
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
             if(i-j==1)
                printf("%d ", m.A[i-2]);
            else if(i-j==0)
            {
                printf("%d ", m.A[m.n-1+i-1]);
            }
            else if(i-j==-1)
            {
                printf("%d ",m.A[2*m.n-1+i-1]);
            }
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
    m.A=(int *)malloc((3*m.n-2)*sizeof(int));

    printf("Enter Elements of matrix ");
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i-j==0||i-j==1||i-j==-1)
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