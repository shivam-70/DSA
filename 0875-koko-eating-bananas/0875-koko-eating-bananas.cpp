class Solution {
public:
    
    bool helper(int val,vector<int>& piles,int h)
    {
        int days=0;
        for(auto it : piles)
        {
            if(it<=val)
                days++;
            else
            {
                if(it%val==0)
                {
                    days+=it/val;
                }
                else
                    days+=(it/val)+1;
            }
        }
        return (days<=h);
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int strt=1;
        int end=*max_element(piles.begin(),piles.end());
        while(strt<end)
        {
            int mid = strt+(end-strt)/2;
            if(helper(mid,piles,h))
                end=mid;
            else
                strt=mid+1;
        }
        return end;
    }
};