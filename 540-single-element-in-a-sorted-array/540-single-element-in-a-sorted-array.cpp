class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int strt=0;
        int end=nums.size()-1;
        while(strt<end)
        {
            int mid=strt+(end-strt)/2;
            if((mid%2==0 and nums[mid]==nums[mid+1]) or (mid%2==1 and nums[mid]==nums[mid-1]))
                strt=mid+1;
            else
                end=mid;
        }
        return nums[strt];
    }
};