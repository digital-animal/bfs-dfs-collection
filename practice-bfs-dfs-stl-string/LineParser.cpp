#include<iostream>
#include<string>
#include<sstream>
#include<vector>

#include<cstring>
using namespace std;

template<typename T>
class LineParser
{
public:
    string str;
    char delim;
    vector<T> output;

public:
    LineParser()
    {
        // pass
    }

    LineParser(string line, char delimeter)
    {
        str = line;
        delim = delimeter;
    }


    vector<T> parseLineToInteger()
    {
        stringstream ss(str);
        string token;
        int num;

        while(getline(ss, token, delim))
        {
            num = stoi(token);
            output.push_back(num);
        }
        return output;
    }

    vector<T> parseLineToChar()
    {
        stringstream ss(str);
        string token;
        char ch;

        while(getline(ss, token, delim))
        {
            ch = token.c_str()[0];
            output.push_back(ch);
        }
        return output;
    }

    vector<T> parseLineToString()
    {
        stringstream ss(str);
        string token;

        while(getline(ss, token, delim))
        {
            output.push_back(token);
        }
        return output;
    }
};

int main()
{
    cout<<"# STRING DEMO:"<<endl;
    string L1 = "The quick brown fox jumps over the lazy dog";
    LineParser<string> parser(L1, ' ');

//    vector<string> words;
    auto words = parser.parseLineToString();

    for(auto word:words)
        cout<<word<<endl;
    cout<<words.size()<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"# CHARACTER DEMO:"<<endl;
    string L2 = "A B C D E F G P Q R";
    LineParser<char> parser2(L2, ' ');

    vector<char> charset;
    charset = parser2.parseLineToChar();

    for(auto ch:charset)
        cout<<ch<<" ";
    cout<<endl;
    cout<<charset.size()<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"# INTEGER DEMO:"<<endl;
    string L3 = "4 9 22 3 57 8 101 6";
    LineParser<int> parser3(L3, ' ');

    vector<int> numbers;
    numbers = parser3.parseLineToInteger();

    for(auto num:numbers)
        cout<<num<<" ";
    cout<<endl;
    cout<<numbers.size()<<endl;
    cout<<endl;

    int sum=0;
    for(auto num:numbers)
    {
        sum = sum + num;
    }
    cout<<"Sum = "<<sum<<endl;
    cout<<endl;

    return 0;
}
