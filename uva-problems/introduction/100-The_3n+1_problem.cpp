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
void find(lli n, int *size)
{
    
    if(n==1)
    {
        (*size)++;
    }
    else
    {
        (*size)++;
        if(n&1) find(3*n+1, size);
        else find(n>>1, size);
    }
}
int main()
{
    lli n,m;
    int size=0, max=0;
    while(scanf("%lld %lld", &n,&m)!=EOF)
    {
        for(int i=n;i<=m;i++)
        {
            find(i, &size);
            if(max < size) max = size;
            size=0;
        }
        cout <<n<<" "<<m<<" "<<max<< endl;
        max=size=0;
    }
}