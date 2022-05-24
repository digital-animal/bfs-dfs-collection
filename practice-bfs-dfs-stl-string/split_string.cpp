#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

void splitLine(string str, vector<string> &words, char delim)
{
    stringstream ss(str);
    string token;
    while(getline(ss, token, delim))
    {
        words.push_back(token);
    }
}

int main()
{
    string str = "The quick brown fox jumps over the lazy dog";
    vector<string> words;
    char delim = ' ';
    splitLine(str, words, delim);

    for(auto word: words)
        cout<<word<<endl;

    cout<<words.size()<<endl;
}
