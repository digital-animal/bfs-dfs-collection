#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

class Graph
{
private:
    int n;
    int e;
    vector<int> *graph;
public:
    /// parameterized constructor
    Graph(int n)
    {
        this->n = n;
        graph = new vector<int>[n];
    }

    /// parameterized constructor
//    Graph(int n, int e)
//    {
//        this->n = n;
//        this->e = e;
//        graph = new vector<int>[n];
//    }

    /// addEdge method
    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
        e++;
    }

    /// createGraph method
    /*
    void createGraph()
    {
        int u,v;
        for(int i=1; i<=e ;i++)
        {
            cout<<"Enter end point of edge "<< i <<"> ";
            cin>>u>>v;
            addEdge(u,v);
        }
    }
    */

    /// getNeighbors methgod
    vector<int> getNeighbors(int v)
    {
        return graph[v];
    }

    /// printGraph method
    void printGraph()
    {
        vector<int>::iterator it;
        for(int i=0; i<n; i++)
        {
            cout<<"# Vertex "<< i <<" => ";
            for(it=graph[i].begin(); it!=graph[i].end(); it++)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
//    Graph g(5,7);

    int n,e;
    cout<<"# Create a Graph"<<endl;
    cout<<"How many Vertices> ";
    cin>>n;
//    cout<<"How many Edges> ";
//    cin>>e;
//    Graph g(n,e);

    Graph g(n);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(1,4);
    g.addEdge(3,4);

//    g.createGraph();
    g.printGraph();

    vector<int> neighbors;
    vector<int>::iterator it;

//    neighbors = g.getNeighbors(0);
//    for(it=neighbors.begin(); it!=neighbors.end(); it++)
//        cout<<*it<<" ";
//    cout<<endl;
//
//    neighbors = g.getNeighbors(1);
//    for(it=neighbors.begin(); it!=neighbors.end(); it++)
//        cout<<*it<<" ";
//    cout<<endl;

    return 0;
}
