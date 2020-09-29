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
void print_v(int* v, int n)
{
    int i;
    cout << "{ ";
    for(i=0;i<n;i++)
    {
        cout << v[i] << ' ';
    }

    cout << "}\n";
}
void perm(int *v, bool *choosen, int i, int n)
{
    if(i<=n) // Keep generating subsets for every recursive call
    {
        for(int j=0; j<n; j++)
        {
            if(choosen[j]==0) // If this number isn't choosen, then use it
            {
                choosen[j]=1; // Check it as choosen
                v[i-1] = j+1; // Add it to the permutation 
                perm(v,choosen,i+1,n); // Calls itself to choose other numbers to permutation or to print the complete permutation if that is the case
                choosen[j]=0; // Set the choosen number as not choosen so it can be used in other recursion branch
            }
        }
        
    }
    else print_v(v,n); // Print the size N permutation of N numbers
}
int main()
{
    int n;
    cin >> n;
    int v[n]={0};
    bool c[n]={0};
    perm(v,c,1,n); //Call {1 ... N}
}