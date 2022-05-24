#include<iostream>
#include<algorithm>
#include<vector>
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
    vector<int> v = {4, 9, 2, 3, 5};
    v.push_back(7);
    v.push_back(8);

    for(auto e:v)
        cout<<e<<" ";
    cout<<endl;

    sort(v.begin(), v.end());

    for(auto e:v)
        cout<<e<<" ";
    cout<<endl;

    sort(v.begin(), v.end(), num_compare);

    for(auto e:v)
        cout<<e<<" ";
    cout<<endl;

    v.pop_back();

    for(auto e:v)
        cout<<e<<" ";
    cout<<endl;

    cout<<v.size()<<endl;
    v.clear();
    cout<<v.size()<<endl;


    return 0;
}

