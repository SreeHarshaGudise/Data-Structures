#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


struct Node
{
    int data;
    struct Node *next;
} *first;

void create(int A[], int n)
{
    int i;
    struct Node *last,*t;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next=NULL;
    last=first;
    
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void DisplayRec(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        DisplayRec(p->next);  // Tail Recursion
    }
    
}

void RevDisplayRec(struct Node *p)
{
    if(p!=NULL)
    {
        RevDisplayRec(p->next); // Head Recursion
        printf("%d ",p->data);
    }
    
}


// This Search is improved as finding the key element from the linked list
// we remove key from the list and place it first of list so that if the same element needs to be found from list
// can be compared and get it from first comparison. 

struct Node * Search(struct Node *p, int key)
{
    struct Node *q;
    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

int Count(struct Node *p)
{
    int cnt=0;
    
    while(p!=NULL)
    {
        cnt++;
        p=p->next;
    }
    return cnt;
}

int Sum(struct Node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int Max(struct Node *p)
{
    int x=INT_MIN;
    while(p!=NULL)
    {
        if(p->data>x)
        {
            x=p->data;
        }
        p=p->next;
    }
    if(x==INT_MIN)
    {
        return 0;
    }
    else return x;
}

int main()
{
    struct Node *temp;
   int A[]={3,2,6,5,10};
   create(A,5);
//    display(first); /* looping way of displaying*/
   DisplayRec(first); /* recursive way of displaying*/
   printf("\n");
   RevDisplayRec(first);

   printf("\nNodes in the linked list are %d ",Count(first));
   printf("\nSum of Nodes in the linked list is %d ",Sum(first));
   printf("\n Max Element of Linked list is %d \n", Max(first));

   temp=Search(first,5);
   if(temp)
    printf("The key %d is found\n: ",temp->data);
   else
    printf("Key Not found \n");

    DisplayRec(first);
    return 0;
}