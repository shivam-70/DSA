class Solution {
public:
    
    bool helper(int src,vector<int> adj[],int color[])
    {
        queue<int> q;
        q.push(src);
        color[src]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it : adj[node])
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                    return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int color[n+1];
        memset(color,-1,sizeof color);
        vector<int> adj[n+1];
        for(auto it : dislikes)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=1;i<=n;i++){
            if(color[i]==-1)
            {
                if(!helper(i,adj,color))
                    return false;
            }
        }
        return true;
    }
};