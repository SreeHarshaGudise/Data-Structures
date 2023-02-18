#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
    char S[]="MADAM";
    int i,j,temp;
    for(j=0;S[j]!='\0';j++)
    {}
    j--;
    //Reversing String Logic
    // for(i=0;i<j;i++,j--)
    // {
    //     temp=S[i];
    //     S[i]=S[j];
    //     S[j]=temp;
    // }
    //Checking if Palindrome or not
    for(i=0;i<j;i++,j--)
    {
        if(S[i]==S[j])
            {continue;}
        else
            {
            cout<< S << " Not Palindrome"<< endl;
            return 0;
            }
            
    }
    

}