class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        
        // for(auto it : prefix)
        //     cout<<it<<" ";
        
        map<int,int> mp;
        int left=0,right=0;
        int ans=0;
        while(right<n)
        {
            if(mp.find(nums[right])!=mp.end())
            {
                left=max(mp[nums[right]]+1,left);
            }
            mp[nums[right]]=right;
            ans=max(ans,prefix[right]-prefix[left]+nums[left]);
            // cout<<ans<<" "<<right<<" "<<left<<endl;
            right++;
        }
        return ans;
    }
};