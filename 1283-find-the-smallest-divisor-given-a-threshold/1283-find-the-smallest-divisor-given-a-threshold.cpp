class Solution {
public:
    
    int helper(int val,vector<int>& arr)
    {
        int sum=0;
        for(auto it : arr)
        {
            sum+=(it+val-1)/val;
        }
            return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        // ceil
        int strt=1;
        int end=*max_element(nums.begin(),nums.end());
        while(strt<end)
        {
            int mid=(strt+end)/2;
            if(helper(mid,nums)>threshold)
                strt=mid+1;
            else
                end=mid;
        }
        return strt;
    }
};