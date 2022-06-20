class Solution {
public:
    
    bool helper(int node,vector<int>& vis,vector<int>& dfsVis,vector<int> adj[])
    {
        vis[node]=1;
        dfsVis[node]=1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(helper(it,vis,dfsVis,adj))
                    return true;
            }
            else if(dfsVis[it])
                return true;
        }
        dfsVis[node]=0;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& v) {
        vector<int> adj[n];
        for(auto it : v)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<int> dfsVis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
               if(helper(i,vis,dfsVis,adj))
                   return false;
            }
        }
        return true;
    }
};