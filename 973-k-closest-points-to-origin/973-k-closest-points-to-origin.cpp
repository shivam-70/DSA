class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        for(auto it : points)
        {
            int dist=it[0]*it[0]+it[1]*it[1];
            pair<int,int> point;
            point.first=it[0];
            point.second=it[1];
            pq.push({dist,point});
            if(pq.size()>k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            vector<int> tmpAns;
            pair<int,int> tmp=pq.top().second;
            pq.pop();
            tmpAns.push_back(tmp.first);
            tmpAns.push_back(tmp.second);
            ans.push_back(tmpAns);
        }
        return ans;
    }
};