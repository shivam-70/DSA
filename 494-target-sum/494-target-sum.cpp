class Solution {
public:
    
    unordered_map<string,int> dp; //Here as per the constraints if I took a 2D integer matrix then
    //the problem was that the target might be negative certain times and negative index will
    // give me error then in use unordered map for it whose solution is goven in the duscussion
    // Section.
    
    
    int helper(vector<int>& nums,int target,int i)
    {
        if(i==nums.size())
        {
            if(target==0)
                return 1;
            
            return 0;
        }
        
        string key=to_string(target)+" "+to_string(i);
        
        if(dp.find(key)!=dp.end())
        {
            return dp[key];
        }
        
        int ans=helper(nums,target-nums[i],i+1)+helper(nums,target+nums[i],i+1);
        
        return dp[key]=ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        
        return helper(nums,target,0);
    
    }
};