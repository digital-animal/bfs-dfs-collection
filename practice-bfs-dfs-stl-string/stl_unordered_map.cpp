#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>

#include<cstring>
#include<cstdio>

using namespace std;

//void printMap(unordered_map<char,int> &m)
//{
//    for(auto &[key, value]: m)
//    {
//        cout<< key <<": "<<value++<<endl;
//    }
//    cout<<endl;
//}

template<class S, class T>
void printMap(unordered_map<S,T> &m)
{
    for(auto &[key, value]: m)
    {
        cout<< key <<": "<<value<<endl;
    }
    cout<<endl;
}


int main()
{
    unordered_map<char,int> M = {{'A',65}, {'B',66}, {'C',67}, {'D',68}, {'E',69},};

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
    cout<<M.empty()<<endl;
    cout<<M.at('A')<<endl;
    cout<<M.at('a')<<endl;

    cout<<endl<<endl;

    unordered_map<string, string> u = {
        {"Red", "#ff0000"},
        {"Green", "#00ff00"},
        {"Blue", "#0000ff"},
    };

    printMap(u);

    cout<< u["Red"] <<endl;
    cout<< u.at("Red") <<endl;
    cout<< u["Black"] <<endl;
//    cout<< u.at("Black") <<endl;
    return 0;
}





