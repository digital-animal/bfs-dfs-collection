#include<iostream>
#include<algorithm>
#include<deque>
#include<string>
#include<cstring>

using namespace std;

bool num_compare(int x, int y)
{
//    return x < y;
    return x > y;
}

bool str_compare(string x, string y)
{
//    return x < y;
//    return x > y;
//    return x.length() > y.length();
//    return x.length() < y.length();
    return strlen(x.c_str()) < strlen(y.c_str());
}

int main()
{
    deque<int> d = {4, 9, 2, 3, 5};
    for(auto x:d)
        cout<<x<<" ";
    cout<<endl;

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    sort(d.begin(), d.end());
    deque<int>::iterator it;
    for(it=d.begin(); it!=d.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    d.push_back(7);
    d.push_front(8);
    for(auto x:d)
        cout<<x<<" ";
    cout<<endl;

//    stable_sort(d.begin(), d.end());
    stable_sort(d.begin(), d.end(), num_compare);
    for(auto x:d)
        cout<<x<<" ";
    cout<<endl;
    cout<<d.size()<<endl;
    cout<<d.max_size()<<endl;
    cout<<d.empty()<<endl;

    d.pop_front();
    for(auto x:d)
        cout<<x<<" ";
    cout<<endl;

    d.pop_back();
    for(auto x:d)
        cout<<x<<" ";
    cout<<endl;

    d.clear();
    for(auto x:d)
        cout<<x<<" ";
    cout<<endl;


    return 0;
}

