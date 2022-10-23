class Solution {
public:
    int helper(int val,vector<int>& arr,int target)
    {
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=min(val,arr[i]);
        }
        return abs(target-sum);
    }
    
    int findBestValue(vector<int>& arr, int target) {
        int strt=0;
        int end=target;
        while(strt<end)
        {
            int mid=(strt+end)/2;
            if(helper(mid,arr,target) <= helper(mid+1,arr,target))
                end=mid;
            else
                strt=mid+1;
        }
        return strt;
    }
};