#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<cstring>
#include<sstream>

#include "LineParser.h"
using namespace std;


class Graph
{
private:
    int n; // no of vertices
    unordered_map<char, vector<char>> G;
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
    }

    /// addEdge method
    void addEdge(int u, int v)
    {
        // pass
    }

    /// addVertex method
    void addVertex(char vertex, vector<char> neighbors)
    {
        G[vertex] = neighbors;
    }

    /// getNeighbors method
    vector<char> getNeighbors(char vertex)
    {
        return G[vertex];
    }


    /// printGraph method
    void printGraph()
    {
        for(char i=0; i<n; i++)
        {
            char key = i + 65;
            cout<<"# Vertex "<< key <<" => ";

            for(auto vertex:G[key])
            {
                cout<<vertex<<" ";
            }
            cout<<endl;
        }
    }

    /// BFS
    vector<char> BFS(char source)
    {
        vector<char> reachableNodes;

        unordered_map<char, bool> visited;

        for(auto &[key, value]:G)
            visited[key] = false;

        char i=source;
        queue<char> Q;

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
            reachableNodes.push_back(i);

            for(auto j:G[i])
            {
                if(visited[j] == false)
                {
                    Q.push(j);
                }
            }
        }
        cout<<endl;
        return reachableNodes;
    }


    /// DFS
    vector<char> DFS(char source)
    {
        vector<char> reachableNodes;
        unordered_map<char, bool> visited;

        for(auto &[key, value]:G)
            visited[key] = false;

        char i=source, j;
        stack<char> S;

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
            reachableNodes.push_back(i);

            for(auto j:G[i])
            {
                if(visited[j] == false)
                {
                    S.push(j);
                }
            }
        }
        cout<<endl;
        return reachableNodes;
    }
};

int main()
{
    /// Example 1
    /*
    unordered_map<char, vector<char>> graph;

    vector<char> A = {'B', 'C'};
    vector<char> B = {'A', 'D'};
    vector<char> C = {'A', 'D'};
    vector<char> D = {'B', 'C'};

    graph['A'] = A;
    graph['B'] = B;
    graph['C'] = C;
    graph['D'] = D;

    BFS(graph, 'A');
    BFS(graph, 'B');
    BFS(graph, 'C');
    BFS(graph, 'D');

    cout<<endl;

    for(auto &[key, value]: graph)
    {
        cout<<key<<" => ";
        for(auto x:value)
            cout<<x<<" ";
        cout<<endl;
    }
    */

    /// Example 2
    /*
    unordered_map<char, vector<char>> graph;

    vector<char> A = {'B', 'C', 'D'};
    vector<char> B = {'A', 'D', 'E'};
    vector<char> C = {'A', 'D'};
    vector<char> D = {'A', 'B', 'C', 'E'};
    vector<char> E = {'B', 'D'};

    graph['A'] = A;
    graph['B'] = B;
    graph['C'] = C;
    graph['D'] = D;
    graph['E'] = E;

    BFS(graph, 'A');
    BFS(graph, 'B');
    BFS(graph, 'C');
    BFS(graph, 'D');
    BFS(graph, 'E');

    cout<<endl;

    for(auto &[key, value]: graph)
    {
        cout<<key<<" => ";
        for(auto x:value)
            cout<<x<<" ";
        cout<<endl;
    }
    */


    int n,e;
    cout<<"# Create a Graph"<<endl;
    cout<<"# Number of Vertex> ";
    cin>>n;
    Graph g(n);

    unordered_map<char, vector<char>> graph;
    char i=0;
    string input;

    for(char i=0; i<n; i++)
    {
        char key = i + 65;
        vector<char> neighbors;
        cout<<"# Enter neighbors of vertex "<<key<<"> ";
        fflush(stdin);
        getline(cin, input);

        LineParser<char> parser(input, ' ');
        neighbors = parser.parseLineToChar();

        /*
        int j=0;
        while(j < input.length())
        {
            if(input[j] >= 65 && input[j] <= 90)
            {
                neighbors.push_back(input[j]);
            }
            j++;
        }
        */

        g.addVertex(key, neighbors);
    }
    cout<<"Graph Created Successfully"<<endl;
    cout<<endl;

    int choice;
    char source;
    int element;
    while(true)
    {
        cout<<"\n ========= M E N U =========="<<endl;
        cout<<" 1. Breadth First Search"<<endl;
        cout<<" 2. Depth First Search"<<endl;
        cout<<" 3. Print HashMap Of Graph"<<endl;
        cout<<" 4. Reachable Nodes from a source"<<endl;
        cout<<" 5. QUIT"<<endl;
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
            {
                cout<<"# Enter source vertex> ";
                cin>>source;
                vector<char> reachableNodes = g.BFS(source);
                cout<<"Reachable Nodes from node "<<source<<": ";
                for(auto node:reachableNodes)
                    cout<<node<<" ";
                cout<<endl;
                break;

            }

        case 5:
            choice = 5;
            cout<<"~PROGRAM TERMINATED"<<endl;
            exit(0);
            cout<<endl;
            break;

        default:
            cout<<"Invalid Choice."<<endl;
            cout<<endl;
            break;
        }
        if(choice == 5) break;
    }

    return 0;
}

