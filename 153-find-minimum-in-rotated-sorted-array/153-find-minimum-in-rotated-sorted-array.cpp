class Solution {
public:
    int findMin(vector<int>& nums) {
        int strt=0,end=nums.size()-1;
        int n=nums.size();
        int prev,next,mid;
        while(strt<=end)
        {
            mid=strt+(end-strt)/2;
            next=(mid+1)%n;
            prev=(mid+n-1)%n;
            // cout<<nums[prev]<<" "<<nums[mid]<<" "<<nums[next]<<endl;
            if(nums[mid]<=nums[prev] and nums[mid]<=nums[next])
                return nums[mid];
            else if(nums[mid]>nums[end]) //rotation occurred and left is sorted
            {
                strt=mid+1;
            }
            else // right is sorted
            {
                end=mid-1;
            }
        }
        return -1;
    }
};