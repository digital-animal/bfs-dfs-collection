#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void BFS(int G[][7], int start, int n)
{
    int i = start, j;
    queue<int> Q;
    int visited[7] = {0};

    cout<<i<<" ";
    visited[i] = 1;
    Q.push(i);

    while(!Q.empty())
    {
        i = Q.front();
        Q.pop();
        for(int j=1; j<n; j++)
        {
            if(G[i][j] == 1 && visited[j] == 0)
            {
                cout<<j<<" ";
                visited[j] = 1;
                Q.push(j);
            }
        }
    }
    cout<<endl;
}

/// DFS Iterative
void DFS(int G[][7], int start, int n)
{
    int i=start, j;
    int visited[7] = {0};
    stack<int> S;

    S.push(i);

    while(!S.empty())
    {
        j = S.top();
        S.pop();
        if(visited[j] == 1)
            continue;

        cout<<j<<" ";
        visited[j] = 1;

        for(int k=0; k<n; k++)
        {
            if(G[j][k] == 1 && visited[k] == 0)
                S.push(k);
        }
    }
    cout<<endl;
}

/// DFS Recursive
/*
void DFS(int G[][7], int start, int n)
{
    static int visited[7] = {0};
    int i = start, j;

    if(visited[i] == 0)
    {
        cout<<i<<" ";
        visited[i] = 1;

        for(j=1; j<n; j++)
        {
            if(G[i][j] == 1 && visited[j] == 0)
            {
                DFS(G,j,n);
            }
        }
    }
}
*/
int main()
{
    int G[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };

    cout<<"# BFS:"<<endl;
    BFS(G, 1, 7);
    BFS(G, 2, 7);
    BFS(G, 3, 7);
    BFS(G, 4, 7);
    BFS(G, 5, 7);
    BFS(G, 6, 7);
    cout<<endl<<endl;

    cout<<"# DFS:"<<endl;
    /// DFS Recursive
//    DFS(G, 1, 7);
//    DFS(G, 2, 7);
//    DFS(G, 3, 7);
//    DFS(G, 4, 7);
//    DFS(G, 5, 7);
//    DFS(G, 6, 7);

    /// DFS Iterative
    DFS(G, 1, 7);
    DFS(G, 2, 7);
    DFS(G, 3, 7);
    DFS(G, 4, 7);
    DFS(G, 5, 7);
    DFS(G, 6, 7);

    return 0;
}
