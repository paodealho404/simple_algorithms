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
#define DBG if(0);

void print_v(int* v, int n)
{
    int i;
    cout << "{ ";
    for(i=0;i<n;i++)
    {
        if(v[i]==1) cout << i+1 << ' ';
    }

    cout << "}\n";
}
void subset(int *v, int i, int n)
{
    if(i<=n) // Keep generating subsets for every recursive call
    {
        v[i-1]=1; // Add an element 'i' in the subset
        subset(v, i+1, n); // Calls itself to keep adding or removing elements that are after the i-th element
        v[i-1]=0; // Remove an element 'i' from the subset
        subset(v, i+1, n); // Calls itself to keep adding or removing elemnts that are after the i-th element
    }
    else print_v(v,n); // Subset processing could be done in this section 
}
int main()
{
    int n;
    cin >> n;
    int v[n]={0};
    subset(v,1,n); //Call {1 ... N}
}