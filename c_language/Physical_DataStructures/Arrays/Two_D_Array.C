#include <stdio.h>
#include <stdlib.h>


int main()
{
    /* Creating 2 d array using stack space method*/
    int A[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    /*Creating array of pointers in stack and assigning arrays to those pointers from heap*/
    int *B[3];

    /*Creating all the array declaring in the heap space itself*/
    int **C;

    B[0]=(int *)malloc(4*sizeof(int));
    B[1]=(int *)malloc(4*sizeof(int));
    B[2]=(int *)malloc(4*sizeof(int));

    C=(int **)malloc(3*sizeof(int));
    C[0]=(int *)malloc(4*sizeof(int));
    C[1]=(int *)malloc(4*sizeof(int));
    C[2]=(int *)malloc(4*sizeof(int));

    for(int i=0;i<3;i++)
    {
        for(int j=0; j<4;j++)
        printf("%d ",C[i][j]);
        printf("\n");
    }
}