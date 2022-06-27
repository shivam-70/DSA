class Solution {
public:
    
    /* 
    Wasn't able to find an effective DP solution hence going for Sliding window approach
    https://www.youtube.com/watch?v=vmY9ctncXQI
    
    excellent explaination
    */
    int getMaxLen(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=0;
        int ans=0;
        for(int i=0;i<n;)
        {
            s=i;
            while(s<n and nums[s]==0) s++;
            e=s;
            int neg=0;
            int firstNeg=-1,lastNeg=-1;
            while(e<n and nums[e]!=0)
            {
                if(nums[e]<0)
                {
                    neg++;
                    if(firstNeg==-1) firstNeg=e;
                    lastNeg=e;
                }
                e++;
            }
            
            if(neg%2==0) ans=max(ans,e-s);
            else
            {
                if(firstNeg!=-1) ans=max(ans,e-firstNeg-1);
                if(lastNeg!=-1) ans=max(ans,lastNeg-s);
            }
            i=e+1;
        }
        return ans;
    }
};