#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

/* For storing a */




struct Matrix
{
    int A[10];
    int S;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if(i==j)
    {
        m->A[i-1]=x;
    }
} 

int Get(struct Matrix m, int i, int j)
{
    if(i==j)
    {
        return m.A[i-1];
    }
    else
        return 0;
}

void Display(struct Matrix m)
{
    int i,j;
    for(i=0;i<m.S;i++)
    {
        for(j=0;j<m.S;j++)
        {
            if(i==j)
            {
                printf("%d ",m.A[i]);
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
    m.S=4;

    Set(&m, 1, 1, 10);Set(&m,2,2,5);Set(&m,3,3,2); Set(&m,4,4,1);

    printf("%d \n",Get(m,2,2));
    Display(m);
  return 0;
}