#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
    char S[10]="John Doe";
    int i=0, cnt=0;
    while(S[i]!='\0')
    {
        cnt++;
        i++;
    }

   printf("%d ", cnt);
   cout<<cnt;
}