#include<iostream>
#include<string>
using namespace std;

int main()
{
    double f1 = 23.43;
    double f2 = 1e-9;
    double f3 = 1e40;
    double f4 = 1e-40;
    double f5 = 123456789;

    string f1_str = to_string(f1);
    string f2_str = to_string(f2);
    string f3_str = to_string(f3);
    string f4_str = to_string(f4);
    string f5_str = to_string(f5);

    cout<<f1<<endl<<f1_str<<endl<<endl;
    cout<<f2<<endl<<f2_str<<endl<<endl;
    cout<<f3<<endl<<f3_str<<endl<<endl;
    cout<<f4<<endl<<f4_str<<endl<<endl;
    cout<<f5<<endl<<f5_str<<endl<<endl;

    string pi_str= "3.14159265358979323846264";
    double pi = stod(pi_str);

    cout<<pi_str<<endl<<pi<<endl<<endl;

    string num_str= "492";
    int num = stoi(num_str);
    cout<<num<<endl<<num++<<endl<<num<<endl<<endl;

    return 0;
}
