#include<iostream>
#include<algorithm>
#include<set>
#include<string>
#include<cstring>

using namespace std;


int main()
{
    set<int> L = {4, 9, 2, 3, 5};

    for(auto e:L)
        cout<<e<<" ";
    cout<<endl;

    cout<<L.empty()<<endl;
    cout<<L.size()<<endl;
    cout<<L.max_size()<<endl;

    L.clear();

    cout<<L.empty()<<endl;
    cout<<L.size()<<endl;

    return 0;
}



