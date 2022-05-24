/// program to remove duplicates from an array
#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>

using namespace std;

vector<int> removeDuplicates(int *A, int n)
{
    vector<int> output;
    unordered_map<int, bool> seen;

    for(int i=0; i<n; i++)
    {
        if(seen.count(A[i]) > 0) continue;
        seen[A[i]] = true;
        output.push_back(A[i]);
    }
    return output;
}

int main()
{
    int A[] = {4, 9, 4, 2, 3, 5, 2, 7, 8, 6, 3, 5, 1, 6, 5, 0, 4, 3};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<n<<endl;

    vector<int> unique_vector;
    unique_vector = removeDuplicates(A, n);

    vector<int>::iterator it1;
    for(it1=unique_vector.begin(); it1!=unique_vector.end(); it1++)
    {
        cout<<*it1<<" ";
    }
    cout<<endl;
    cout<<unique_vector.size()<<endl;
    cout<<unique_vector.capacity()<<endl;
    cout<<unique_vector.front()<<endl;
    cout<<unique_vector.back()<<endl;

    return 0;
}


