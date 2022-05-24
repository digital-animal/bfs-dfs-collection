#include<iostream>
#include<algorithm>

using namespace std;

void printArray(int *A, int n)
{
    for(int i=0; i<n; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = {4, 9, 2, 3, 5, 7, 8, 1, 6, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);
    sort(arr, arr+n);
    printArray(arr, n);

    return 0;
}
