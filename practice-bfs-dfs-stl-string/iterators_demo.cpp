#include<iostream>
//#include<unordered_map>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main()
{
//    unordered_map<string, int> ourmap;
    map<string, int> ourmap;
    ourmap["Babar"] = 27;
    ourmap["Zahid"] = 29;
    ourmap["Jewel"] = 26;
    ourmap["Robi"] = 30;
    ourmap["Tonmoy"] = 31;
    ourmap["Hasan"] = 25;

//    unordered_map<string, int>::iterator it;
    map<string, int>::iterator it;

    for(it=ourmap.begin(); it!=ourmap.end(); it++)
    {
        cout<< it->first <<": "<< it->second <<endl;
    }
    cout<<endl;

    vector<int> v;
    v.push_back(4);
    v.push_back(9);
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);

    vector<int>::iterator iter;
    iter = v.begin();

    while(iter!=v.end())
    {
        cout<< *iter <<" ";
        iter++;
    }

    cout<<endl;
    map<string, int>::iterator map_iter;
    map_iter = ourmap.find("Robi");
    cout<< map_iter->first <<endl;
    cout<< map_iter->second <<endl;
}
