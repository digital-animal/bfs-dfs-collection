#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

class Graph
{
private:
    int n; // no of vertices
    int e; // no of edges
    vector<int> *G;
public:
    /// default constructor
    Graph()
    {
        // pass
    }

    /// parameterized constructor

    Graph(int n)
    {
        this->n = n;
        G = new vector<int>[n];
    }

    /// parameterized constructor
    Graph(int n, int e)
    {
        this->n = n;
        this->e = e;

        G = new vector<int>[n];
    }

    /// addEdge method
    void addEdge(int u, int v)
    {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    /// getNeighbors methgod
    vector<int> getNeighbors(int v)
    {
        return G[v];
    }


    /// printGraph method
    void printGraph()
    {
        vector<int>::iterator it;

        for(int i=0; i<n; i++)
        {
            cout<<"# Vertex "<< i <<" => ";
            for(it=G[i].begin(); it!=G[i].end(); it++)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
        }
    }

    /// BFS
    void BFS(int source)
    {

        vector<bool> visited(this->n, false);

        int i=source;
        queue<int> Q;

        Q.push(i);

        cout<<source<<" => ";

        while(!Q.empty())
        {
            i = Q.front();
            Q.pop();

            if(visited[i] == true)
                continue;

            cout<<i<<" ";
            visited[i] = true;

            for(auto j:G[i])
            {
                if(visited[j] == false)
                {
                    Q.push(j);
                }
            }
        }
        cout<<endl;
    }

    /// DFS
    void DFS(int source)
    {
        vector<bool> visited(this->n, false);

        int i=source, j;
        stack<int> S;

        S.push(i);

        cout<<source<<" => ";

        while(!S.empty())
        {
            i = S.top();
            S.pop();

            if(visited[i] == true)
                continue;

            cout<<i<<" ";
            visited[i] = true;

            for(auto j:G[i])
            {
                if(visited[j] == false)
                {
                    S.push(j);
                }
            }
        }
        cout<<endl;
    }
};

int main()
{
    int n,e;
    cout<<"# Create a Graph"<<endl;
    cout<<"# Number of Vertex> ";
    cin>>n;
    cout<<"# Number of Edge> ";
    cin>>e;
    Graph g(n,e);

    int i=0;
    int u,v;
    while(i<e)
    {
        cout<<"# Enter (u,v) of Edge "<<i+1<<"> ";
        cin>>u>>v;
        g.addEdge(u,v);
        i++;
    }
    cout<<"Graph Created Successfully"<<endl;
    cout<<endl;

    int choice;
    int source;
    int element;
    while(true)
    {
        cout<<"\n ========= M E N U =========="<<endl;
        cout<<" 1. Breadth First Search"<<endl;
        cout<<" 2. Depth First Search"<<endl;
        cout<<" 3. Print Adjacency List Of Graph"<<endl;
        cout<<" 4. QUIT"<<endl;
        cout<<" ====================\n"<<endl;
        cout<<"## Enter your choice> ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"# Enter source vertex> ";
            cin>>source;
            g.BFS(source);
            break;

        case 2:
            cout<<"# Enter source vertex> ";
            cin>>source;
            g.DFS(source);
            break;

        case 3:
            g.printGraph();
            break;
        case 4:
            choice = 4;
            cout<<"~PROGRAM TERMINATED"<<endl;
            exit(0);
            cout<<endl;
            break;
        default:
            cout<<"Invalid Choice."<<endl;
            cout<<endl;
            break;
        }
        if(choice == 14) break;
    }

    return 0;
}
