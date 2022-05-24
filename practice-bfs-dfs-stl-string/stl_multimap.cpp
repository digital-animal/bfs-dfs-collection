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

void printMap(multimap<string, int> person)
{

    for(auto [name, age]: person)
        cout<<"person["<< name << "] = "<< age << endl;
    cout<<endl;
}

int main()
{

    multimap<string, int> person = {
                        {"Zahid", 30},
                        {"Jewel", 29},
                        {"Robi", 28},
                        {"Abid", 26},
                        {"Hasan", 31},
                        {"Galib", 26},
                        {"Priton", 25},
                        {"Zahid", 21},
                        {"Abid", 32},
                    };

    printMap(person);

    person.insert(make_pair("Mushfiq", 34));
    person.insert({"Rhaman", 32});
    person.insert(pair<string, int> ("Talha", 32));

    printMap(person);

    multimap<string, int> friends(person.begin(), person.end());

    friends.insert({"Nazmul", 30});

    printMap(friends);

    cout<<person.size()<<endl;
    cout<<friends.size()<<endl;

    return 0;
}

