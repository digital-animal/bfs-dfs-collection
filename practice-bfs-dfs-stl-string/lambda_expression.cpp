#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    /// example 1
    vector<int> c = {4, 9, 2, 3, 5, 7, 8, 1, 6, 0};
    int x = 5;
//    c.erase(remove_if(c.begin(), c.end(), [x](int n){return n < x;}), c.end());
    c.erase(remove_if(c.begin(), c.end(), [x](int n){return n > x;}), c.end());
    for(auto e:c)
        cout<<e<<" ";
    cout<<endl;

    /// example 2
    for_each(c.begin(), c.end(), [](int i){cout<<i<<" ";});
    cout<<endl;

    /// example 3
//    auto func1 = [](int i=6){return i+4;};
//    cout<<func1()<<endl;

    /// example 4
    auto func2 = [](int i){return i+4;};
    cout<<func2(5)<<endl;

    return 0;
}
