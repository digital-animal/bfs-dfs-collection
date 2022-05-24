#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<utility>
#include<string>
#include<fstream>

#include<cstdio>
#include<cctype>

#include "LineParser.h"

using namespace std;

class Graph
{
private:
    int n; // number of vertices
    int e; // number of edges

    int currenTotalTreasures;
    int collectedTreasures;
    unordered_map< int, vector< pair<int,int> > > adjList; // adjacency list to represent graph
    unordered_map<int, bool> visited; // to track visited node in BFS and DFS
    unordered_map<int, int> pieceCollection; // to track which friend collected how many pieces
public:
    /// default constructor
    Graph()
    {
        n = 0;
        currenTotalTreasures = 0;
        collectedTreasures = 0;
    }

    /// addEdge method
    void addEdge(int u, int v)
    {
        adjList[u].push_back({v, 0}); // every node is stored as pair
        adjList[v].push_back({u, 0});
        e++;
    }

    /// BFS
    /// returns collected pieced in each call (traversal)
    int BFS(int source)
    {
        int collectedPieces = 0;

        for(auto &[key, value]: adjList)
            visited[key] = false;

        visited[source] = true;

        queue<int> Q;
        Q.push(source);

//        printf("# BFS(%d) => ", source);

//        cout<< source <<" ";
        while(!Q.empty())
        {
            int parentNode = Q.front();
            Q.pop();

            for(auto &eachNode: adjList[parentNode])
            {
                if(visited[eachNode.first] == false)
                {
//                    cout<<eachNode.first<<" "; // visit done

                    visited[eachNode.first] = true;
                    Q.push(eachNode.first);

                    if(currenTotalTreasures - eachNode.second >= 0)
                    {
                        currenTotalTreasures -= eachNode.second; // if visited, deduct the treasures in that node
                        collectedPieces += eachNode.second;
                    }
                }
                eachNode.second = 0;
            }
        }

        return collectedPieces;
    }


    /// DFS
    /// returns collected pieced in each call (traversal)
    int DFS(int source)
    {
        int collectedPieces = 0;

        for(auto &[key, value]: adjList)
            visited[key] = false;

        visited[source] = true;

        stack<int> S;
        S.push(source);

//        printf("#DFS(%d) => ", source);
        while(!S.empty())
        {
            int parentNode = S.top();
            S.pop();

            for(auto &eachNode: adjList[parentNode])
            {
                if(visited[eachNode.first] == false)
                {
//                    cout<<eachNode.first<<" "; // visit done

                    visited[eachNode.first] = true;
                    S.push(eachNode.first);

                    if(currenTotalTreasures - eachNode.second >= 0)
                    {
                        currenTotalTreasures -= eachNode.second; // if visited, deduct the treasures in that node
                        collectedPieces += eachNode.second;
                    }
                }
                eachNode.second = 0; // as visited, so treasure is set to 0
            }
        }

        return collectedPieces;
    }

    /// =============== Treasure Hunt Part =================

    /// addTreasure method
    void addTreasure(pair<int,int> t)
    {
        for(auto &[key, nodeList]: adjList)
        {
            for(auto &eachNode: nodeList)
            {
                if(eachNode.first == t.first && eachNode.second == 0)
                {
                    eachNode.second += t.second;
                }
            }
        }
        currenTotalTreasures = currenTotalTreasures + t.second;
    }

    /// startTreasureHunt method
    void startTreasureHunt(pair<int,int> t, int algoChoice)
    {

        int source = t.first; // city no
        int friendNo = t.second; // friend no

        int collectedPieces;

        if(algoChoice == 1)
            collectedPieces= BFS(t.first);

        else if(algoChoice == 2)
            collectedPieces = DFS(t.first);

        pieceCollection[friendNo] = collectedPieces; // updating piece collection map
        collectedTreasures += collectedPieces;
    }

    /// huntResult
    void huntResult()
    {
        ofstream fout;
        fout.open("mission_result.txt");

        if(currenTotalTreasures > 0)
        {
            cout<<"# Mission Impossible"<<endl;
            fout<<"# Mission Impossible\n";
        }
        else
        {
            cout<<"# Mission Accomplished"<<endl;
            fout<<"# Mission Accomplished\n";
        }

        int total = collectedTreasures + currenTotalTreasures;

        printf("%d out of %d pieces collected\n", collectedTreasures, total);
        fout<< collectedTreasures <<" out of "<< total <<" pieces collected\n";

        for(auto [friendNo,collectedPieces]: pieceCollection)
        {
            printf("Friend %d collected %d pieces\n", friendNo, collectedPieces);
            fout<<"Friend "<< friendNo <<" collected "<< collectedPieces <<" pieces\n";
        }

        fout.close();
    }

    /// printGraph
    void printGraph()
    {
        for(auto [key,List]: adjList)
        {
            printf("# Node %d: ", key);
            for(auto node: List)
            {
//                cout<<node.first<<" ";
                printf("[%d, %d] ", node.first, node.second);
            }
            cout<<endl;
        }
    }
};


/// Calling Functions
/// isValid method to validate and limit input to numeric value only
bool isValid(string str)
{
    bool valid = true;

    for(int i=0; i<str.length(); i++)
    {
        if( !( (str[i] >= 48 && str[i] <= 57) || str[i] == 32 ) )
           return valid = false;
    }
    return valid;
}

/// createTreasureHunt Function
void createTreasureHunt(int algoChoice)
{
    Graph G;

    cout<<"# C R L F:"<<endl;
    /// C = no of cities
    /// R = no of roads
    /// L = no of locations i.e. cities where treasure is hidden L <= R
    /// F = no of treasure hunter friends
    int C,R,L,F;
//    cin>>C>>R>>L>>F;

    string input;

    cout<<"> ";
    fflush(stdin);
    getline(cin, input);

    if(isValid(input))
    {
        LineParser<int> parser(input, ' ');
        auto nums = parser.parseLineToInteger();
        if(nums.size()!=4)
        {
            cout<<"Invalid Input"<<endl;
            return;
        }
        C = nums[0];
        R = nums[1];
        L = nums[2];
        F = nums[3];
    }
    else
    {
        cout<<"Invalid Input"<<endl;
        return;
    }

    cout<<endl;

    cout<<"# C1 C2:"<<endl;
    /// C1 & C2 two cities connecting Road R
    int C1,C2;
    for(int i=0; i<R; i++)
    {
        cout<<"> ";
        fflush(stdin);
        getline(cin, input);

        if(isValid(input))
        {
            LineParser<int> parser(input, ' ');
            auto nums = parser.parseLineToInteger();
            if(nums.size()!=2)
            {
                cout<<"Invalid Input"<<endl;
                return;
            }
            C1 = nums[0];
            C2 = nums[1];
        }
        else
        {
            cout<<"Invalid Input"<<endl;
            return;
        }

//        cin>>C1>>C2;
        G.addEdge(C1,C2);
    }
    cout<<endl;

    cout<<"# Cx Px:"<<endl;
    /// Cx = City no where treasure is hidden
    /// Px = Total treasures hidden in city Cx
    int Cx,Px;
    for(int i=0; i<L; i++)
    {
        cout<<"> ";
        fflush(stdin);
        getline(cin, input);

        if(isValid(input))
        {
            LineParser<int> parser(input, ' ');
            auto nums = parser.parseLineToInteger();

            if(nums.size()!=2)
            {
                cout<<"Invalid Input"<<endl;
                return;
            }

            Cx = nums[0];
            Px = nums[1];
        }
        else
        {
            cout<<"Invalid Input"<<endl;
            return;
        }

//        cin>>Cx>>Px;
        G.addTreasure(make_pair(Cx,Px));
    }
    cout<<endl;

    cout<<"# Cy Fy:"<<endl;
    /// Cy = starting city for treasure hunt
    /// Fy = friend no starting treasure hunt from city Cy
    int Cy,Fy;
    for(int i=0; i<F; i++)
    {
        cout<<"> ";
        fflush(stdin);
        getline(cin, input);

        if(isValid(input))
        {
            LineParser<int> parser(input, ' ');
            auto nums = parser.parseLineToInteger();

            if(nums.size()!=2)
            {
                cout<<"Invalid Input"<<endl;
                return;
            }

            Cy = nums[0];
            Fy = nums[1];
        }
        else
        {
            cout<<"Invalid Input"<<endl;
            return;
        }

//        cout<<"> ";
//        cin>>Cy>>Fy;
        G.startTreasureHunt(make_pair(Cy,Fy), algoChoice);
    }
    cout<<endl;

    G.huntResult();
}

int main()
{
    string input;
    int choice;
    int algoChoice;
    while(true)
    {
        cout<<"\n ================ M E N U ==============="<<endl;
        cout<<" 1. Create & Explore Treasure Hunt (BFS)"<<endl;
        cout<<" 2. Create & Explore Treasure Hunt (DFS)"<<endl;
        cout<<" 3. QUIT"<<endl;
        cout<<" ========================================"<<endl;
        cout<<" # Enter your choice> ";

        fflush(stdin);
        getline(cin, input);

        if(isValid(input))
        {
            LineParser<int> parser(input, ' ');
            auto nums = parser.parseLineToInteger();

            if(nums.size()!=1)
            {
                cout<<"Invalid Input. Try Again"<<endl;
                continue;
            }

            choice = nums[0];
        }
        else
        {
            cout<<"Invalid Input. Try Again"<<endl;
            continue;
        }

        switch(choice)
        {
        case 1:
            algoChoice = 1;
            createTreasureHunt(algoChoice);
            break;

        case 2:
            algoChoice = 2;
            createTreasureHunt(algoChoice);
            break;

        case 3:
            choice = 3;
            cout<<"~PROGRAM TERMINATED"<<endl;
            exit(0);
            cout<<endl;
            break;

        default:
            cout<<"Invalid Choice."<<endl;
            cout<<endl;
            break;
        }
        if(choice == 3) break;
    }

    return 0;
}

