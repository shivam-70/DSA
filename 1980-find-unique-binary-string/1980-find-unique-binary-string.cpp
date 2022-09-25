class Solution {
public:
    unordered_map<string,bool> mp;
    string ans;
    
    void helper(string str,vector<string>& nums)
    {
        if(str.length()==nums[0].length())
        {
            if(mp.find(str)==mp.end())
            {
                ans=str;
                return;
            }
        }
        else
        {
            helper(str+'0',nums);
            helper(str+'1',nums);
        }
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        string str;
        for(auto it : nums)
        {
            mp[it]=true;
        }
        helper(str,nums);
        return ans;
    }
};