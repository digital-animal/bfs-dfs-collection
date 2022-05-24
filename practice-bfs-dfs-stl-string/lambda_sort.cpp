#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

#include<cmath>
using namespace std;

bool abssort(float a, float b)
{
    return abs(a) > abs(b);
}

void printArray(int *A, int n)
{
    for(int i=0;i <n; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

int add(int x, int y)
{
    return x+y;
}

int multiply(int x, int y)
{
    return x*y;
}

int main()
{
    /// example 1
    int A[] = {4, 9, 2, 3, 5, 7, 8, 1, 6, 0};
    int n = sizeof(A) / sizeof(A[0]);

    printArray(A, n);
//    sort(A, A+n , abssort);
    sort(A, A+n , [](int x, int y){return abs(x) > abs(y);});
    printArray(A, n);
    cout<<endl;

    /// example 2
    int B[] = {2, 3, 5, 7, 11, 13, 17, 21, 23, 29};
    int m = sizeof(B) / sizeof(B[0]);
    int sum=0;
    cout<< accumulate(B, B+n, sum)<<endl;
    cout<< accumulate(B, B+n, sum, [&sum](auto x, auto y){ return x + y; }) <<endl;
    cout<< accumulate(B, B+n, sum, add) <<endl;

    /// example 3
    int mul=1;
    int C[] = {2, 3, 5, 7, 11};
    int t = sizeof(C) / sizeof(C[0]);

    cout<< accumulate(C, C+t, mul, multiply) <<endl;
    cout<< accumulate(C, C+t, mul, [&mul](auto x, auto y){ return x*y; }) <<endl;

    return 0;
}

