#include<iostream>
#include<algorithm>
#include<array>
#include<string>
#include<cstring>

using namespace std;

bool num_compare(int x, int y)
{
//    return x < y;
    return x > y;
}

bool str_compare(string x, string y)
{
//    return x < y;
//    return x > y;
//    return x.length() > y.length();
//    return x.length() < y.length();
    return strlen(x.c_str()) < strlen(y.c_str());
}

int main()
{
    cout<<"============= INTEGER ARRAY ============"<<endl;
    array<int, 10> arr = {4,9,2,3,5,7,8,1,6,0};
    cout<<arr.size()<<endl;
    cout<<arr.max_size()<<endl;
    cout<<arr.empty()<<endl;

    array<int, 10>::iterator it;

    for(it=arr.begin(); it!=arr.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;


    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++)
    {
        cout<< arr[i] <<" ";
    }
    cout<<endl;

    stable_sort(arr.begin(), arr.end(), num_compare);
    for(auto element:arr)
    {
        cout<< element <<" ";
    }
    cout<<endl;


    cout<<"============= STRING ARRAY ============"<<endl;
    array<string, 5> names = {"Zahid","Jewel", "Robi", "Tonmoy", "Hasan"};

    for(auto name:names)
    {
        cout<< name <<" ";
    }
    cout<<endl;

    sort(names.begin(), names.end());

    for(auto name:names)
    {
        cout<< name <<" ";
    }
    cout<<endl;

    sort(names.begin(), names.end(), str_compare);

    for(auto name:names)
    {
        cout<< name <<" ";
    }
    cout<<endl;

    swap(names[0], names[4]);
    for(auto name:names)
    {
        cout<< name <<" ";
    }
    cout<<endl;

    names[0].swap(names[1]);
    for(auto name:names)
    {
        cout<< name <<" ";
    }
    cout<<endl;
//    cout<<names.at(0)<<endl;
//    cout<<names.at(1)<<endl;
//    cout<<names.at(2)<<endl;
//    cout<<names.at(3)<<endl;
//    cout<<names.at(4)<<endl;
//    cout<<names.at(5)<<endl;

    cout<<names.front()<<endl;
    cout<<names.back()<<endl;


    return 0;
}
