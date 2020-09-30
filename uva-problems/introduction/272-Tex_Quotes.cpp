#include<iostream>
using namespace std;
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<string>
typedef unsigned long long int ulli;
typedef long int li;
typedef long long int lli;
typedef struct a A;
#define DBG if(0)
struct a
{
};

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
void print_v(int* v, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
}
int main()
{
    string v;
    string o="``";
    string c="''";
    bool close=false;
    while (getline(cin,v))
    {
        for(int i=0; i<v.length();i++)
        {   
            if(v.at(i)=='"')
            {
                close ? v.replace(i,1,c) : v.replace(i,1,o);
                close = !close;
            }
        }
        cout << v << endl;
    }
}