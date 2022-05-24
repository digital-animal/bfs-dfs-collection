#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;

bool isNumeric(string str)
{
    for(int i=0; i<str.length(); i++)
    {
        if(isdigit(str[i]) == false)
           return false;
    }
    return true;
}

/// isValid method to limit input to numeric value only
bool isValid(string str)
{
    bool valid = true;

    for(int i=0; i<str.length(); i++)
    {
        if( !( (str[i] >= 48 && str[i] <= 57) || str[i] == 32 ) )
           return valid = false;
    }
    return valid;
}

int main()
{
    /// isNumeric example
    /*
    int number;
    cout<<"# Enter a number> ";
    cin>>number;

    string num_str = to_string(number);
    cout<<num_str<<endl;

    if(isNumeric(num_str) == true)
    {
        cout<<"Numeric"<<endl;
    }
    else
    {
        cout<<"Not Numeric"<<endl;
    }
    */

    /// isValid example
    cout<<"# Enter a line> ";
    fflush(stdin);

    string line;
    getline(cin, line);

    if(isValid(line) == true)
    {
        cout<<"Valid Input"<<endl;
    }
    else
    {
        cout<<"Invalid Input"<<endl;
    }

    return 0;
}
