class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it : times)
        {
            adj[it[0]].push_back({it[2],it[1]});
        }
        
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k}); // distance and source
        dist[k]=0;
        while(!pq.empty())
        {
            pair<int,int> x = pq.top();
            pq.pop();
            for (auto neighbor : adj[x.second]) {
                int ar = dist[x.second] + neighbor.first;
                if (ar < dist[neighbor.second]) {
                    dist[neighbor.second] = ar;
                    pq.push(make_pair(ar, neighbor.second));
                }
            }  
        }
        for(int i=1;i<=n;i++)
        {
            cout<<dist[i]<<" ";
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,dist[i]);
        }
        return (ans==INT_MAX)?-1:ans;
    }
};