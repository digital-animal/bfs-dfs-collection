/// DFS
void DFS(int source)
{
    vector<bool> visited(n, false);

    int i=source;
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

        for(auto j:getNeighbors(i))
        {
            if(visited[j] == false)
            {
                S.push(j);
            }
        }
    }
    cout<<endl;
}
