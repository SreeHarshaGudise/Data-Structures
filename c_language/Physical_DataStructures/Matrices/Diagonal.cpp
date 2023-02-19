#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


/* 
-> For storing nxn diagonal matrix :
* As Diagonal Matrix dont have elements on upper and lower traingular space, 
  it occupies only diagonal space.
* For size n it will be having n diagonal elements.
* For storing those we need and array of size n. */


class Diagonal
{
    private:
        int n;
        int *A;
    public:
        Diagonal(int n)
        {
            this->n=n;
            A=new int[n];
        }
        ~Diagonal()
        {
            delete []A;
        }
        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
};

void Diagonal::Set(int i, int j, int x)
{
    if(i==j)
    {
        A[i-1]=x;
    }
}

int Diagonal::Get(int i, int j)
{
    if(i==j)
    {
        return A[i-1];
    }
    else
        return 0;
}

void Diagonal::Display()
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                cout<<A[i]<<" "; 
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
} 


int main()
{
    Diagonal d(4);
    d.Set(1,1,5); d.Set(2,2,10); d.Set(3,3,7); d.Set(4,4,8);
    cout<<d.Get(3,3)<<" ";
    d.Display();
  return 0;
}