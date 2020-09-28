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
void merge(int *v, int s, int m, int e)
{
    int sizeL = m-s+1; // size of the left array
    int sizeR = e-m; // size of the right array

    // create temporary arrays to copy data
    int L[sizeL], R[sizeR],i,j,k;
    for(i=0;i<sizeL;i++) L[i] = v[s+i];
    for(j=0;j<sizeR;j++) R[j] = v[(m+1)+j];

    // merging temporary arrays back into v[s...e]
    i=j=0; // initial index of first and second subarray set to 0

    k=s; // k is the initial index of the merged subarray
    while(i<sizeL && j<sizeR)
    {
        if(L[i]<=R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements of L[] in v[s....e], if there are any left
    while(i<sizeL)
    {
        v[k] = L[i];
        i++;
        k++;
    }

    // copy the remaining elements of R[] in v[s....e], if there are any left
    while(j<sizeR)
    {
        v[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int *v, int b, int e)
{
    // make a simple check if begin  position is still minor than the end position, otherwise it has length 0
    if(b<e)
    {
        //int m = (b+e)/2; //middle point of vector
        int m = b + (e-b)/2; //use it to avoid long integers problems
        //remember break it in subproblems (divide and conquer), small pieces of the vector
        //merge_sort to left
        merge_sort(v, b, m);
        //merge_sort to right
        merge_sort(v,m+1,e);
        //at this point, both (left and right) portions are ready to merge
        merge(v, b, m, e);
    }
}
int main()
{
    int n;
    cin >> n;
    int v[n], i;
    for(i=0;i<n;i++)
    {
        cin >> v[i];
    }
    merge_sort(v,0,n-1);
    cout << "Sorted array ";
    print_v(v, n);
}