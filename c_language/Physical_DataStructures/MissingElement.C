#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Array {
    int A[10];
    int size;
    int length;
};

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void Display(struct Array ar)
{
    int i;
    for(i=0;i<ar.length;i++)
    {
        printf("%d ",ar.A[i]);
    }
    printf("\n");
}

/*missing elements from sorted array code
    int diff = ar.A[0]- 0, j;

    printf("Missing elements from array are: ");
    for(j=0;j<ar.length;j++)
    {
        if((ar.A[j]-j) != diff)
        {
            while(diff<ar.A[j]-j)
            {
                printf("%d ",j+diff);
                diff++;
            }
        }
    }
*/



int main()
{
    struct Array ar={{8,2,4,10,12,1},10,6};

    int A[12]={0},i,j;

    Display(ar);

    for(i=0;i<ar.length;i++)
    {
        A[ar.A[i]]++;
    }

    for(j=1;j<12;j++)
    {
        // printf("%d ",A[j]);
        if(A[j]==0)
        {
            printf("%d ",j);
        }
    }

}