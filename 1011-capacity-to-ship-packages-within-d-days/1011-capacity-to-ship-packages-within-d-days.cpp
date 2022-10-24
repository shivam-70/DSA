class Solution {
public:
    
    bool helper(int cap,vector<int>& weights,int days)
    {
        int tmp=0;
        int tmpDays=0;
        for(int i=0;i<weights.size();i++)
        {
            if(weights[i]>cap)
                return false;
            if(tmp+weights[i]>cap)
            {
                tmpDays++;
                tmp=weights[i];
            }
            else
            {
                tmp+=weights[i];
            }
        }
        if(tmp<=cap)
            tmpDays++;
        return (tmpDays<=days);
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int strt=1;
        int end=accumulate(weights.begin(),weights.end(),0);
        // sort(weights.begin(),weights.end());
        while(strt<end)
        {
            int mid=strt+(end-strt)/2;
            // cout<<strt<<" "<<end<<" "<<mid<<endl;
            if(helper(mid,weights,days))
            {
                end=mid;
            }
            else
            {
                strt=mid+1;
            }
        }
        return end;
    }
};