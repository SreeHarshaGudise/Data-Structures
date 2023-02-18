#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
    char S[]="hello";
    long int A=0,X=0; 
    int i;
    for(i=0;S[i]!='\0';i++)
    {
        X=1;
        X=X<<(S[i]-97);
        if((X & A) > 0)
        {
            cout<<"Duplicate in String "<<S<< " Is "<< S[i];
        }
        else{
            A=X|A;
        }
    }

  return 0;
}