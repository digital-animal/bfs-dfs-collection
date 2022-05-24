#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<climits>
using namespace std;

class Graph
{
private:
    int n; // no of vertices
    int e; // no of edges
    unordered_map<int, vector<int>> adjList;
    // map<int, vector<int>> adjList;

    unordered_map<int, bool> visited;
    unordered_map<int, int> distance;
    unordered_map<int, int> predecessor;

    // map<int, bool> visited;

public:
    // default constructor
    Graph()
    {
        n = 0;
        e = 0;
        // pass
    }

    // parameterized constructor
    Graph(int n)
    {
        this->n = n;
    }

    // parameterized constructor
    Graph(int n, int e)
    {
        this->n = n;
        this->e = e;
    }

    // addEdge method
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        e++;
    }

    // getTotalNodes
    int getTotalNodes()
    {
        n = adjList.size();

        return n;
    }

    // getTotalEdges
    int getTotalEdges()
    {
        return e;
    }

    // getNodeDistance method
    int getNodeDistance(int src, int dest)
    {
        BFS(src);

        if(visited[dest] == false)
        {
            return -1;
        }

        return distance[dest];
    }

    // getShortestPath method
    void getShortestPath(int src, int dest)
    {
        BFS(src);

        if(visited[dest] == false)
        {
            printf("# No path between %d and %d\n", src, dest);
            return;
        }

        printf("# Shortest Path (%d, %d): ", src, dest);

        int current = dest;
        stack<int> path;

        while(true) // creating path
        {
            if(current == -1) break; // i.e. reaching root(source)

            path.push(current);
            current = predecessor[current];
        }

        // printing path
        while(!path.empty())
        {
            if(path.top() == dest)
            {
                cout<<path.top()<<" ";
                path.pop();
                break;
            }

            cout<<path.top()<<" = > ";
            path.pop();
        }
        cout<<endl;
    }

    // isNodeReachable method
    bool isNodeReachable(int src, int dest)
    {
        BFS(src);
        // if(visited[dest] == true)
        //     return true;
        // return false;
         
        return visited[dest];
    }

    // BFS
    void BFS(int source)
    {
        for(auto &[key, value]: adjList)
        {
            visited[key] = false;
            distance[key] = INT_MAX;
            predecessor[key] = -1;

        }

        distance[source] = 0;
        visited[source] = true;

        queue<int> Q;
        Q.push(source);

        printf("# BFS(%d) => ", source);

        cout<< source <<" ";
        while(!Q.empty())
        {
            int parentNode = Q.front();
            Q.pop();

            for(auto eachNode: adjList[parentNode])
            {
                if(visited[eachNode] == false)
                {
                    cout<<eachNode<<" "; // visit done

                    visited[eachNode] = true;
                    distance[eachNode] = distance[parentNode] + 1;
                    predecessor[eachNode] = parentNode;
                    Q.push(eachNode);
                }
            }
        }
        cout<<endl;
    }

    /// DFS
    void DFS(int source)
    {
        for(auto &[key, value]: adjList)
        {
            visited[key] = false;
            distance[key] = INT_MAX;
            predecessor[key] = -1;
        }

        stack<int> S;
        S.push(source);

        printf("#DFS(%d) => ", source);
        while(!S.empty())
        {
            int parentNode = S.top();
            S.pop();

            cout<<parentNode<<" ";
            visited[parentNode] = true;

            for(auto eachNode: adjList[parentNode])
            {
                if(visited[eachNode] == false)
                {
                    
                    visited[eachNode] = true;
                    distance[eachNode] = distance[parentNode] + 1;
                    predecessor[eachNode] = parentNode;
                    S.push(eachNode);
                }
            }
        }
        cout<<endl;
    }

    // printGraph
    void printGraph()
    {
        for(auto &[key, nodeList]: adjList)
        {
            printf("# Node %d: ", key);
            for(auto &node: nodeList)
            {
                cout<<node<<" ";
            }
            cout<<endl;
        }
    }

};

int main()
{
    int n, e;
    cout<<"# Create a Graph"<<endl;
    cout<<"# Number of Vertex> ";
    cin>>n;
    cout<<"# Number of Edges> ";
    cin>>e;

    Graph G;

    string input;
    int u;
    int v;
    for(int i=0; i<e; i++)
    {
        cout<<"# Enter endpoint(u,v) of edge "<<i+1<<"> ";
        cin>>u>>v;
        G.addEdge(u,v);
    }
    cout<<"Graph Created Successfully"<<endl;
    cout<<endl;

    int choice;
    int source;
    int destination;
    int element;

    while(true)
    {
        cout<<"\n ========= M E N U =========="<<endl;
        cout<<" 1. Print Graph"<<endl;
        cout<<" 2. Breadth First Search (BFS)"<<endl;
        cout<<" 3. Depth First Search (DFS)"<<endl;
        cout<<" 4. Get Minimum Distance"<<endl;
        cout<<" 5. Get Shortest Path"<<endl;
        cout<<" 6. Check Connectivity"<<endl;
        cout<<" 7. Get Total Nodes"<<endl;
        cout<<" 8. Get Total Edges"<<endl;
        cout<<" 9. QUIT"<<endl;
        cout<<" ==============================\n"<<endl;
        cout<<"## Enter your choice> ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            G.printGraph();
            break;

        case 2:
            cout<<"# Enter source vertex> ";
            cin>>source;
            G.BFS(source);
            break;

        case 3:
            cout<<"# Enter source vertex> ";
            cin>>source;
            G.DFS(source);
            break;

        case 4:
            {
                cout<<"# Enter source vertex> ";
                cin>>source;
                cout<<"# Enter destination vertex> ";
                cin>>destination;
                int distance = G.getNodeDistance(source, destination);

                if(distance == -1)
                {
                    printf("# No path between %d and %d\n", source, destination);
                    break;
                }
                printf("# Minimum Distance (%d, %d) = %d\n", source, destination, distance);
                break;

            }
        case 5:
            cout<<"# Enter source vertex> ";
            cin>>source;
            cout<<"# Enter destination vertex> ";
            cin>>destination;
            G.getShortestPath(source, destination);
            break;

        case 6:
            {
                cout<<"# Enter source vertex> ";
                cin>>source;
                cout<<"# Enter destination vertex> ";
                cin>>destination;
                bool isConnected = G.isNodeReachable(source, destination);

                if(isConnected == false)
                {
                    printf("# %d is not reachable from %d\n", source, destination);
                    break;
                }
                printf("# %d is reachable from %d\n", source, destination);
                break;
            }

        case 7:
            printf("# Total Nodes = %d\n", G.getTotalNodes());
            break;

        case 8:
            printf("# Total Edges = %d\n", G.getTotalEdges());
            break;

        case 9:
            choice = 9;
            cout<<"~PROGRAM TERMINATED"<<endl;
            exit(0);
            cout<<endl;
            break;
        default:
            cout<<"Invalid Choice."<<endl;
            cout<<endl;
            break;
        }
        if(choice == 9) break;
    }

    return 0;
}

