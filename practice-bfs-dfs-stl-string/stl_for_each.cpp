#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> A = {4, 9, 2, 3, 5, 7, 8, 1, 6, 0};

    int sum = 0;
    for_each(A.begin(), A.end(), [&](int x){ sum = sum+x;});
    cout<<"Sum = "<< sum <<endl;

    return 0;
}
