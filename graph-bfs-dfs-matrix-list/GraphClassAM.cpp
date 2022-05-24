#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Graph
{
private:
    int n; // no of vertices
    int e; // no of edges
    int **G;
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

        G = new int*[n];
        for(int i=0; i<n; i++)
            G[i] = new int[n];

        /// solution from stack overflow
        /*
        int *arr = new int[(n+1)*(n+1)];
        //arr[i][j] is then rewritten as
        //arr[i*(n+1)+j]
        */
    }

    /// parameterized constructor
    Graph(int n, int e)
    {
        this->n = n;
        this->e = e;

        G = new int*[n];
        for(int i=0; i<n; i++)
            G[i] = new int[n];

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                G[i][j] = 0;

    }

    /// addEdge method
    void addEdge(int u, int v)
    {
        G[u][v] = 1;
        G[v][u] = 1;
    }

    /// createGraph method
    /*
    void createGraph()
    {
        int u,v;
        for(int i=1; i<=e ;i++)
        {
            cout<<"# Enter (u,v) of edge "<<i+1<<"> ";
            cin>>u>>v;
            addEdge(u,v);
        }
    }
    */

    /// printGraph method
    void printGraph()
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<G[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    /// BFS
    void BFS(int source)
    {
        cout<<source<<" => ";

        int *visited = new int[this->n];
        for(int k=0; k<n; k++)
            visited[k] = 0;

        int i=source, j;
        queue<int> Q;

        Q.push(i);
        cout<<i<<" ";
        visited[i] = 1;

        while(!Q.empty())
        {
            i = Q.front();
            Q.pop();

            for(int j=0; j<n; j++)
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

    /// DFS
    void DFS(int source)
    {
        int *visited = new int[this->n];
        for(int k=0; k<n; k++)
            visited[k] = 0;

        int i=source, j;
        stack<int> S;

        S.push(i);

        cout<<source<<" => ";

        while(!S.empty())
        {
            i = S.top();
            S.pop();

            if(visited[i] == 1)
                continue;

            cout<<i<<" ";
            visited[i] = 1;

            for(int j=0; j<n; j++)
            {
                if(G[i][j] == 1 && visited[j] == 0)
                {
                    S.push(j);
                }
            }
        }
        cout<<endl;
    }

    /// destructor
    ~Graph()
    {
        for(int i=0; i<n+1; i++)
            delete[] G[i];
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

    /// Testing
    /**
    cout<<"# Adj Matrix Representation:"<<endl;
    g.printGraph();
    cout<<endl;

    cout<<"# BFS:"<<endl;
    g.BFS(0);
    g.BFS(1);
    g.BFS(2);
    g.BFS(3);
    cout<<endl;

    cout<<"# DFS:"<<endl;
    g.DFS(0);
    g.DFS(1);
    g.DFS(2);
    g.DFS(3);
    cout<<endl;
    */

    int source;
    int element;
    while(true)
    {
        cout<<"\n ========= M E N U =========="<<endl;
        cout<<" 1. Breadth First Search"<<endl;
        cout<<" 2. Depth First Search"<<endl;
        cout<<" 3. Print Adjacency Matrix Of Graph"<<endl;
        cout<<" 4.QUIT"<<endl;
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
