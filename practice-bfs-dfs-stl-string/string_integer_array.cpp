#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

void parseLine(string str, vector<int> &numbers, char delim)
{
    stringstream ss(str);
    string token;
    int num;

    while(getline(ss, token, delim))
    {
        num = stoi(token);
        numbers.push_back(num);
    }
}

int main()
{
    string str = "4 9 2 3 5 7";
    vector<int> numbers;
    char delim = ' ';
    parseLine(str, numbers, delim);
//
//    for(auto num: numbers)
//        cout<<num++<<endl;

    for(auto &num: numbers)
        cout<<num++<<" ";

    cout<<endl;
    cout<<numbers.size()<<endl;

    for(auto num: numbers)
        cout<<num<<" ";
    cout<<endl;
}

