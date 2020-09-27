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
void swap (int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
void print_v(int *v, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;
}
void insertion(int *v, int n)
{   
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key = v[i];
        j=i-1;
        while (j>=0 && key<v[j])
        {
            swap(v[j], v[j+1]);
            j--;
        }
        v[j+1]=key;
        // print_v(v,n); //uncomment to show each step in this sorting algorithm
    }
}
int main()
{
    int n;
    cin >> n;
    int v[n],i;
    for(i=0;i<n;i++)
    {
        cin >> v[i];
    }
    insertion(v,n);
    print_v(v,n);
}