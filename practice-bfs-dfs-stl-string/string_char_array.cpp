#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

void parseLineToChar(string str, vector<char> &charset, char delim)
{
    stringstream ss(str);
    string token;
    char ch;

    while(getline(ss, token, delim))
    {
        ch = token.c_str()[0];
        charset.push_back(ch);
    }
}

int main()
{
    string str = "A B C D E";
    vector<char> charset;
    char delim = ' ';

    parseLineToChar(str, charset, delim);


//    for(auto &ch: charset)
//        cout<<ch<<" ";

    for(auto &ch: charset)
        cout<<ch<<endl;

    cout<<charset.size()<<endl;
}


