class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int idx=abs(nums[i])-1;
            // cout<<idx<<" "<<nums[idx-1]<<endl;
            if(nums[idx]>0)
            {
                nums[idx]*=-1;
            }
        }
        for(auto it : nums)
        {
            cout<<it<<" ";
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                ans.push_back(i+1);
        }
        return ans;
    }
};