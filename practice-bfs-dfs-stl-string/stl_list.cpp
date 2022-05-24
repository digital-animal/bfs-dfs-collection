#include<iostream>
#include<algorithm>
#include<list>
#include<string>
#include<cstring>

using namespace std;

int main()
{
    list<int> L = {4, 9, 2, 3, 5};
    L.push_back(7);
    L.push_back(8);

    for(auto e:L)
        cout<<e<<" ";
    cout<<endl;

    cout<<L.front()<<endl;
    cout<<L.back()<<endl;

    L.pop_back();

    for(auto e:L)
        cout<<e<<" ";
    cout<<endl;

    L.pop_front();

    for(auto e:L)
        cout<<e<<" ";
    cout<<endl;

    L.reverse();

    for(auto e:L)
        cout<<e<<" ";
    cout<<endl;

    L.sort();

    for(auto e:L)
        cout<<e<<" ";
    cout<<endl;

    cout<<L.size()<<endl;
    L.clear();
    cout<<L.size()<<endl;

    return 0;
}


