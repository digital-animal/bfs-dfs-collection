#include<iostream>
#include<algorithm>
#include<string>
#include<array>
#include<vector>
#include<numeric>

#include<cstring>
#include<cstdio>

using namespace std;

void printArray(int *A, int n)
{
    for(int i=0; i<n; i++)
        cout<< A[i] <<" ";
    cout<<endl;
}

template<class T>
void printVector(vector<T> &v)
{
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
}
int main()
{
//    int A[] = {4, 9, 2, 3, 5, 7, 8, 1, 6, 0};
    int A[] = {4, 9, 2, 3, 5, 7, 8, 1, 6, 10};
    int n = sizeof(A)/sizeof(A[0]);
    printArray(A, n);

    vector<int> arr;
    for(int i=0; i<n; i++)
        arr.push_back(A[i]);

//    printVector(arr);
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++)
        A[i] = arr.at(i);

    printArray(A,n);

    auto max_ptr = max_element(arr.begin(), arr.end());
    cout<<"Maxima = "<< *max_ptr <<endl;

    auto min_ptr = min_element(arr.begin(), arr.end());
    cout<<"Minima = "<< *min_ptr <<endl;

    const auto [minima, maxima] = minmax_element(arr.begin(), arr.end());
    cout<<"Min = "<<*minima<<", Max = "<<*maxima<<endl;

//    cout<<std::max(4, 9)<<endl;
    cout<<max(4, 9)<<endl;
    cout<<max({4, 9, 2, 3, 13})<<endl;

    cout<<min(4, 9)<<endl;
    cout<<min({4, 9, 2, 3, -40})<<endl;

    int sum = accumulate(arr.begin(), arr.end(), 0); // initial sum = 0
    cout<<"Sum = "<<sum<<endl;

    int product = accumulate(arr.begin(), arr.end(), 1, multiplies<int>()); // initial product = 1
    cout<<"Product = "<<product<<endl;

    return 0;
}









