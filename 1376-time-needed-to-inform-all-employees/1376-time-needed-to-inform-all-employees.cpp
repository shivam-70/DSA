class Solution {
public:
    
    /*
    Hame har level ka maximum chahiye
    */
    unordered_map<int,vector<int>> adj;
    int ans=0,duration=0;
    void dfs(int manager,vector<int>& informTime)
    {
        ans=max(ans,duration);
        for(auto it : adj[manager])
        {
            duration+=informTime[manager];
            dfs(it,informTime);
            duration-=informTime[manager]; // waapis usee level ki value laane ke liye    
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i=0;i<n;i++)
        {
            adj[manager[i]].push_back(i);
        }
        dfs(headID,informTime);
        return ans;
    }
};