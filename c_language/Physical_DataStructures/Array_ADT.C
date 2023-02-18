#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Create Abstract Data Type of Array with pointer, size and length variables */
struct Array{
    int A[10];
    int size;
    int length;
};


/*Pass the declared array structure to Function*/
void Display(struct Array ar)
{
    int j;
    for(j=0;j<ar.length;j++)
    {
        printf(" %d  ",ar.A[j]);
    }
    printf("\n");
}

/*inserting a number at given index*/
void Insert(struct Array *ar, int index, int data)
{
    int i;
    /*Check if index is greater than 0 and less than the length of array*/
    if(index>=0 && index<=ar->length)
    {
        /* Move all elements to right starting from index place*/
        for(i=ar->length;i>index;i--)
            ar->A[i]=ar->A[i-1];
        ar->A[index]=data;
        ar->length++;
    }
}

/*Appending a number at end of array*/
void Append(struct Array *ar, int data)
{
    if(ar->length<ar->size)
    {
        ar->A[ar->length++]=data;
    }
    
    // printf("Array has no space to insert new data ");
    // printf("\nlength of array is %d", ar.length);
}

/* Deleting an element at index and fill it with foremost elements*/
int Delete(struct Array *ar, int index)
{
    int i,x;
    printf("\nDeleting element at index %d \n",index);

    if(index>=0 && index<ar->length)
    {
        x=ar->A[index];
        for(i=index;i<ar->length-1;i++)
            {
                ar->A[i]=ar->A[i+1];
            }
        ar->length--;
        return x;
    }
    
    return 0;
}

/*Normal Loop Searching*/
int LinearSearch(struct Array ar, int data)
{
    int i;
    for(i=0; i<ar.length; i++)
    {
        if(ar.A[i]==data)
        {
            return i;
        }
    }
    return -1;
}


/*Recursive way of Binary Search*/
int BSearchRecursion(int a[], int l, int h, int data)
{
    int mid;
    mid = (l+h)/2;
    if(a[mid]==data)
    {
        return mid;
    }
    else if(data<a[mid])
    {
        return BSearchRecursion(a,l,mid-1,data);
    }
    else    
    {
        return BSearchRecursion(a,mid+1,h,data);
    }
}



/*logic for binary search mid=l+h/2 */
int BinarySearch(struct Array ar, int data)
{
    int i,l=0,h=ar.length-1,mid;
    for(i=l;i<=h;i++)
    {
        mid = (l+h)/2;
        if(data==ar.A[mid])
        {
            return mid;
        }
        else if(data<ar.A[mid])
        {
            h=mid-1;
        }
        else if(data>ar.A[mid])
        {
            l=mid+1;
        }
    }
    return -1;
}

void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

/*Reverse an array without auxilary array*/
void Reverse(struct Array *ar)
{
    int i, j;
     for(i=0,j=ar->length-1;i<j;i++,j--)
        {
            swap(&ar->A[i],&ar->A[j]);
        }
}

int SortArrayCheck(struct Array ar)
{
    int i;
    for(i=0;i<ar.length-1;i++)
    {
        if(ar.A[i]>ar.A[i+1])
            return 0;
    }
    return 1;
}

struct Array *MergeArrays(struct Array ar1, struct Array ar2)
{
    int i=0,j=0,k=0;
    struct Array *p=(struct Array *)malloc((ar1.length+ar2.length)*sizeof(struct Array));
    while(i<ar1.length&&j<ar2.length)
    {
        if(ar1.A[i]<ar2.A[j])
        {
            p->A[k++]=ar1.A[i++];
        }
        else
            p->A[k++]=ar2.A[j++];
    }
    for(;i<ar1.length;i++)
    {
        p->A[k++]=ar1.A[i];
    }
    for(;j<ar2.length;j++)
    {
        p->A[k++]=ar2.A[j];
    }
    p->length=ar1.length+ar2.length;
    p->size=10;
    return p;
    /* code to put in main
    struct Array *mrarr;
    mrarr=MergeArrays(arr,arr2);*/
}

int main()
{
    int n, i;
    struct Array arr={{1,2,4,6,8},10,5};
    
    
    Display(arr);
   
    return 0;
}