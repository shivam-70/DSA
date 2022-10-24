class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        if(nums[0]>nums[1])
            return 0;
        if(nums[n-1]>nums[n-2])
            return n-1;
        int strt=1;
        int end=n-2;
        while(strt<=end)
        {
            int mid=strt+(end-strt)/2;
            if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1])
                return mid;
            if(nums[mid]>nums[mid-1])
                strt=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
};