/// BFS
void BFS(int source)
{

    vector<bool> visited(n, false);

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

        for(auto j:getNeighbors(i))
        {
            if(visited[j] == false)
            {
                Q.push(j);
            }
        }
    }
    cout<<endl;
}
