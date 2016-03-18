#include<iostream>
#include<string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
bool possible(char *u, char *v, char *w);
int main()
{
    char u[10];
    char v[10];
    char w[10];
    gets(u);
    gets(v);
    gets(w);
    if(possible(u,v,w)) cout<<"Dasie"; else cout<<"nie da sie";
}

bool possible(char *u, char *v, char *w)
{
        int A[26];
        for(int i=0;i<26;i++)A[i]=0;
        for(int i=0;i<strlen(u);i++) A[(int)u[i]-97]++;
        for(int i=0;i<strlen(v);i++) A[(int)v[i]-97]++;
        for(int i=0;i<strlen(w);i++) A[(int)w[i]-97]--;
        for(int i=0;i<26;i++)
        {
            if(A[i]<0) return false;
        }
        return true;
}
