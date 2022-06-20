class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> adj; //isliye liye hai kahe ki hamko negative value ke saath store krna hai aur iski 
         //aadat daal lo kahe ki non continuous nodes ke liye efficient rhta hai chutiye.
        for(int i=0;i<n;i++)
        {
            adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;// node and duration( how much time we have taken to reach there)
        q.push({headID,0}); // head me first time zero sec me phoche. ab dkehenge kitna time info dispatch krne me lageyaga
        int ans=0;
        while(!q.empty())
        {
            int sie=q.size();
            while(sie--){
            int node=q.front().first;
            int timeTaken=q.front().second;
            q.pop();
            int duration=timeTaken+informTime[node];//ye duration info dispatch krne me lageyga aage.
            ans=max(ans,duration);
            for(auto it : adj[node])
            {
                q.push({it,duration}); // aage ke saare nodes me abhi hi to pahche ho. Ab aage kb dispatc karega ye aage 
                // jab queue se dispatch krna to dekhna.
            }
            }
        }
        return ans;
    }
};