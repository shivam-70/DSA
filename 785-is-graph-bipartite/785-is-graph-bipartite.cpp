class Solution {
public:
    
    bool helper2(int node,vector<int> adj[],int color[])
    {
        for(auto it : adj[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                if(!helper2(it,adj,color))
                    return false;
            }
            else if(color[it]==color[node])
                return false;
        }
        return true;
    }
    
    bool helper1(int n,vector<int> adj[])
    {
        int color[n];
        memset(color,-1,sizeof color);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=1;
                if(!helper2(i,adj,color))
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        if(helper1(n,adj))
            return true;
        return false;
    }
};