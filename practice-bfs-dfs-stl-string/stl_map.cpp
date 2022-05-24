#include<iostream>
#include<algorithm>
#include<map>
#include<string>

#include<cstring>
#include<cstdio>

using namespace std;

void printMap(map<char,int> &m)
{
//    for(auto [key, value]: m)
//    {
//        cout<< key <<": "<<value++<<endl;
//    }
//    cout<<endl;

    for(auto &[key, value]: m)
    {
        cout<< key <<": "<<value++<<endl;
    }
    cout<<endl;
}


int main()
{
    map<char,int> M = {{'A',65}, {'B',66}, {'C',67}, {'D',68}, {'E',69},};

    printMap(M);

    cout<<endl;

    printMap(M);

    M['F']=70;
    M['a']=97;
    M['b']=98;
    M['c']=99;
    M['d']=100;

    printMap(M);

    cout<<M.count('F')<<endl;
    cout<<M.count('f')<<endl;
    cout<<M.size()<<endl;
    cout<<M.max_size()<<endl;

    return 0;
}




