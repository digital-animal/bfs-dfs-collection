#include<iostream>
#include<algorithm>
#include<forward_list>
#include<string>
#include<cstring>

using namespace std;


int main()
{
    forward_list<int> L = {4, 9, 2, 3, 5};
    L.push_front(7);

    for(auto e:L)
        cout<<e<<" ";
    cout<<endl;

    cout<<L.front()<<endl;

    L.pop_front();

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

    cout<<L.empty()<<endl;
    cout<<L.max_size()<<endl;
    L.clear();
    cout<<L.empty()<<endl;

    return 0;
}



