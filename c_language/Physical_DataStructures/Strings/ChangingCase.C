#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
    char S[]="Welcome To The Data Structures Lecture";
    int i,j;
    for(i=0;S[i]!='\0';i++)
    {
        if(S[i]>=65 && S[i]<=90)
        {
            S[i]+=32;
        }
        else if(S[i]>=97 && S[i]<=122)
        {
            S[i]-=32;
        }
    }
    cout<<S;
  return 0;
}