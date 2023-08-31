

bool dfs(vector<int> graph[],int vertex,int parent,vector<int> &visited)
{
    visited[vertex]=1;
    for(auto child:graph[vertex])
    {
        if(visited[child] && child!=parent)
        {
            return true;
        }
        else if(visited[child])
        continue;
        else
        {
            if(dfs(graph,child,vertex,visited))
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> graph[n+1];
    for(auto it:edges)
    {
        int u=it[0];
        int v=it[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> visited(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(visited[i]!=1)
        {
            if(dfs(graph,i,-1,visited))
            return "Yes";
        }
    }
   
    return "No";
   
}