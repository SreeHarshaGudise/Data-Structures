#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;



/* Ways to represent a sparse matrix using array
matrix which has major number of elements as zero
row.     m  1 2 4
col      n  3 1 3
non-zero 4  8 7 8
*/

struct Elements
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int x;
    int y;
    int num;
    struct Elements *ele;
};

void create(struct Sparse *s)
{
    int i;
    printf("Enter the Dimensions of matrix ");
    scanf("%d%d",&s->x,&s->y);
    printf("Enter number of non-zero elements in matrix ");
    scanf("%d",&s->num);
    
    s->ele = (struct Elements *)malloc(s->num*sizeof(struct Elements));
    printf("Entering non-zero elements into the matrix ");
    for(i=0;i<s->num;i++)
    {
        scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
    }
}

void display(struct Sparse s)
{
    int i,j,k=0;
    for(i=0;i<s.x;i++)
    {
        for(j=0;j<s.y;j++)
        {
            if(i==s.ele[k].i && j==s.ele[k].j)
            {
                printf("%d ",s.ele[k++].x);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n ");
    }
}


int main()
{
    struct Sparse s;
    create(&s);
    display(s);
  return 0;
}