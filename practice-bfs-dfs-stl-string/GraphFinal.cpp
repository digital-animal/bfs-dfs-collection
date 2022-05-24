#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<limits>
using namespace std;

class Graph
{
private:
    int n;
    int e;
    unordered_map<int, vector<int>> adjList;
//    map<int, vector<int>> adjList;

    unordered_map<int, bool> visited;
    unordered_map<int, int> distance;
    unordered_map<int, int> predecessor;

//        map<int, bool> visited;

public:
    /// constructor
    Graph()
    {
        n = 0;
        // pass
    }

    /// addEdge method
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        e++;
    }

    /// getTotalNodes

    int getTotalNodes()
    {
        n = adjList.size();

        return n;
    }

    /// getTotalEdges
    int getTotalEdges()
    {
        return e;
    }

    /// getNodeDistance method
    void getNodeDistance(int src, int dest)
    {
        BFS(src);

        if(visited[dest] == false)
        {
            printf("# No path between %d and %d\n", src, dest);
            return;
        }

        printf("# Minimum Distance (%d, %d) = %d\n", src, dest, distance[dest]);
    }

    /// getShortestPath method
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

        while(true) /// creating path
        {
            if(current == -1) break;

            path.push(current);
            current = predecessor[current];
        }

        /// printing path
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

    /// isNodeReachable method
    bool isNodeReachable(int src, int dest)
    {
        BFS(src);
        if(visited[dest] == true)
            return true;
        return false;
    }

    /// BFS
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


        //printf("# BFS(%d) => ", source);

        ///cout<< source <<" ";
        while(!Q.empty())
        {
            int parentNode = Q.front();
            Q.pop();

            for(auto eachNode: adjList[parentNode])
            {
                if(visited[eachNode] == false)
                {
                    ///cout<<eachNode<<" "; // visit done

                    visited[eachNode] = true;
                    distance[eachNode] = distance[parentNode] + 1;
                    predecessor[eachNode] = parentNode;
                    Q.push(eachNode);
                }
            }
        }
        ///cout<<endl;
    }

    /// DFS
    void DFS(int source)
    {
        for(auto &[key, value]: adjList)
            visited[key] = false;

        int i = source;

        stack<int> S;
        S.push(i);

        printf("#DFS(%d) => ", source);
        while(!S.empty())
        {
            int j = S.top();
            S.pop();

            if(visited[j] == true)
                continue;

            cout<<j<<" ";
            visited[j] = true;

            for(auto eachNode: adjList[j])
            {
                if(visited[eachNode] == false)
                    S.push(eachNode);
            }
        }
        cout<<endl;
    }

    /// printGraph
    void printGraph()
    {
        for(auto &[key,List]: adjList)
        {
            cout<<"# "<<key<<" => ";
            for(auto &element: List)
            {
                cout<<element<<" ";
            }
            cout<<endl;
        }
        cout<<"# Total Nodes = "<<getTotalNodes()<<endl;
        cout<<"# Total Edges = "<<getTotalEdges()<<endl;
    }

};

int main()
{
    /// Example 1
//    Graph graph;
//    graph.addEdge(0, 1);
//    graph.addEdge(0, 2);
//    graph.addEdge(0, 3);
//    graph.addEdge(1, 3);
//    graph.addEdge(2, 3);
//    graph.printGraph();

    /// Example 2
//    Graph graph;
//    graph.addEdge(0, 1);
//    graph.addEdge(0, 2);
//    graph.addEdge(1, 2);
//    graph.addEdge(1, 3);
//    graph.addEdge(1, 4);
//    graph.addEdge(2, 4);
//    graph.addEdge(3, 4);
//    graph.addEdge(3, 5);
//    graph.addEdge(4, 5);
//
//    graph.addEdge(6, 7);
//    graph.addEdge(6, 8);
//    graph.addEdge(7, 8);
//    graph.printGraph();

    /// Example 2
    Graph graph;

    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);
    graph.addEdge(3, 7);
    graph.addEdge(4, 5);
    graph.addEdge(4, 6);
    graph.addEdge(4, 7);
    graph.addEdge(5, 6);
    graph.addEdge(6, 7);

    graph.printGraph();

    /*
    graph.BFS(0);
    graph.BFS(1);
    graph.BFS(2);
    graph.BFS(3);
    graph.BFS(4);
    graph.BFS(5);
    cout<<endl;

    graph.DFS(0);
    graph.DFS(1);
    graph.DFS(2);
    graph.DFS(3);
    graph.DFS(4);
    graph.DFS(5);
    cout<<endl;
    */

    /*
    cout<<graph.isNodeReachable(0, 4)<<endl;
    cout<<graph.isNodeReachable(0, 5)<<endl;
    cout<<graph.isNodeReachable(0, 6)<<endl;
    cout<<endl;
    */

//    graph.getNodeDistance(0, 1);
//    graph.getNodeDistance(0, 3);
//    graph.getNodeDistance(0, 4);
//    graph.getNodeDistance(0, 5);
//    graph.getNodeDistance(0, 8);
//    graph.getNodeDistance(5, 5);
//    graph.getNodeDistance(5, 5);
//    cout<<endl;

//    graph.getShortestPath(0, 1);
//    graph.getShortestPath(0, 3);
//    graph.getShortestPath(0, 4);
//    graph.getShortestPath(0, 5);
//    graph.getShortestPath(0, 6);
//    graph.getShortestPath(5, 5);

    graph.getNodeDistance(0, 1);
    graph.getNodeDistance(0, 2);
    graph.getNodeDistance(0, 7);
    graph.getNodeDistance(2, 6);
    cout<<endl;

    graph.getShortestPath(0, 1);
    graph.getShortestPath(0, 2);
    graph.getShortestPath(0, 7);
    graph.getShortestPath(2, 6);


    return 0;
}
