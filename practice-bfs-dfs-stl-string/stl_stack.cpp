#include<iostream>
#include<algorithm>
#include<stack>
#include<string>

#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    stack<string> S;
    S.push("Zahid");
    S.push("Robi");
    S.push("Jewel");
    S.push("Hasan");
    S.push("Tonmoy");

    cout<<S.top()<<endl;
    cout<<S.size()<<endl;

//    for(int i=0; i<S.size(); i++)
//    {
//        cout<<S.top()<<" ";
//        S.pop();
//    }

    while(!S.empty())
    {
        cout<<S.top()<<" ";
        S.pop();
    }
    cout<<endl;

    return 0;
}






