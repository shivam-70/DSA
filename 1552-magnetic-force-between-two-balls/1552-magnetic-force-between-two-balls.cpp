class Solution {
public:
    
    bool helper(vector<int>& pos,int m,int mid)
    {
        int prev=pos[0];
        int balls=1;
        for(int i=1;i<pos.size();i++)
        {
            if((pos[i]-prev)>=mid)
            {
                if(++balls==m)
                    return true;
                prev=pos[i];
            }
        }
        return false;
    }
    
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int n=pos.size();
        int low=1;
        int high=pos[n-1]-pos[0];
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(helper(pos,m,mid))
            {
                low=mid+1;
                ans=mid;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};