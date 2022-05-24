#include<iostream>
#include<algorithm>
#include<queue>
#include<string>

#include<cstring>
#include<cstdio>

using namespace std;


int main()
{
    queue<string> Q;
    Q.push("Zahid");
    Q.push("Robi");
    Q.push("Jewel");
    Q.push("Hasan");
    Q.push("Tonmoy");

    cout<<Q.front()<<endl;
    cout<<Q.size()<<endl;


    while(!Q.empty())
    {
        cout<<Q.front()<<" ";
        Q.pop();
    }
    cout<<endl;

    return 0;
}







