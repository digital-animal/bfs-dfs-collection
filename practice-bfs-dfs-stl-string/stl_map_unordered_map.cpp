#include<iostream>
#include<map>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>

#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
//    map<string, int> person = {
//                        {"Zahid", 30},
//                        {"Jewel", 29},
//                        {"Robi", 28},
//                        {"Abid", 26},
//                        {"Hasan", 31},
//                        {"Galib", 26},
//                        {"Priton", 25},
//                    };
    unordered_map<string, int> person = {
                        {"Zahid", 30},
                        {"Jewel", 29},
                        {"Robi", 28},
                        {"Abid", 26},
                        {"Hasan", 31},
                        {"Galib", 26},
                        {"Priton", 25},
                    };

    for(auto [name, age]: person)
    {
//        printf("person[%s] = %d\n", name, age);
        cout<<"person["<< name << "] = "<< age << endl;
    }

    return 0;
}
