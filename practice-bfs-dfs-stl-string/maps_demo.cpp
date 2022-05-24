#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main()
{
    unordered_map<string, int> ourmap;

    pair<string, int> person("Kalam", 34);
    ourmap.insert(person);

    ourmap["Babar"] = 27;
    ourmap["Azam"] = 29;
    ourmap["Zahid"] = 29;
    ourmap["Jewel"] = 26;
    ourmap["Robi"] = 30;
    ourmap["Tonmoy"] = 31;
    ourmap["Hasan"] = 25;

    unordered_map<string, int>::iterator it;

//    it = ourmap.begin();
//    while(it!=ourmap.end())
//    {
//        cout<<it->first<<": "<<it->second<<endl;
//        it++;
//    }


//    for(it=ourmap.begin(); it!=ourmap.end(); it++)
//    {
//        cout<<it->first<<": "<<it->second<<endl;
//    }

    for(auto [key, value]:ourmap)
    {
        cout<<key<<": "<<value<<endl;
    }

//    cout<<endl;
//    cout<<ourmap["Kalam"]<<endl;
//    cout<<ourmap.at("Kalam")<<endl;
//    cout<<ourmap["Abid"]<<endl;
////    cout<<ourmap.at("Abid")<<endl;
//    cout<<ourmap.count("Abdi")<<endl;
//    cout<<ourmap.count("Hasan")<<endl;
//
//    if(ourmap.count("Robi") > 0)
//    {
//        cout<<"Robi Present"<<endl;
//    }
//    cout<<ourmap.size()<<endl;
//    cout<<ourmap.erase("Abid")<<endl;
//    cout<<ourmap.size()<<endl;

    return 0;
}

