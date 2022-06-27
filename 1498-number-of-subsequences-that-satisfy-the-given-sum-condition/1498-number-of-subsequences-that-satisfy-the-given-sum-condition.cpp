#define mod 1000000007
class Solution {
public:
    /*
    https://www.youtube.com/watch?v=nxWT_mG-x54
    
    Explained really well and can be applied for all the questions like this.
    */
    
    long helper(int x,int y)
    {
        if(y==0)
            return 1;
        if(y==1)
            return x;
        long ans=1;
        if(y%2)
        {
            ans=x*helper(x,y-1);
        }
        else
        {
            ans=helper(x,y/2);
            ans*=ans;
        }
        return ans%mod;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int s=0,e=n-1;
        while(s<=e)
        {
            if(nums[s]+nums[e]<=target)
            {
                ans+=helper(2,e-s);
                ans%=mod;
                s++;
            }
            else
            {
                e--;
            }
        }
        return ans;
    }
};