#include<stdio.h>
#include<stdlib.h>


int main()
{
    int A[] = {1,3,4,5,5,6,8,8,9}, i,j=0;


    printf("Printing Duplicate Elements in sorted array: ");
    for(i=0;i<9;i++)
    {
        if(A[i]==A[i+1])
        {
            j=A[i];
            printf("%d ", A[i]);
        }
    }
    printf("The last duplicate element in the array is: %d",j);
}