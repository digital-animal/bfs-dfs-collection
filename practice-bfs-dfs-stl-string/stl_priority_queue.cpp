#include<iostream>
#include<algorithm>
#include<queue>
#include<string>

#include<cstring>
#include<cstdio>

using namespace std;


int main()
{
//    priority_queue<int> Q;
//    priority_queue<int, vector<int>, less<int> > Q;
//    priority_queue<int, vector<int>, less_equal<int> > Q;
//    priority_queue<int, vector<int>, greater<int> > Q;
    priority_queue<int, vector<int>, greater_equal<int> > Q;

    Q.push(4);
    Q.push(9);
    Q.push(2);
    Q.push(3);
    Q.push(5);
    Q.push(7);
    Q.push(8);
    Q.push(1);
    Q.push(6);
    Q.push(0);

    cout<<Q.top()<<endl;
    cout<<Q.size()<<endl;


    while(!Q.empty())
    {
        cout<<Q.top()<<" ";
        Q.pop();
    }
    cout<<endl;

    return 0;
}








