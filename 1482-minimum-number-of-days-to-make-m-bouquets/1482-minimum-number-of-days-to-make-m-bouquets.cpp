class Solution {
public:
    
    bool helper(long long val,vector<int>& a,int m,int k)
    {
        int subArray=0,ans=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]<=val)
            {
                subArray++;
            }
            else
            {
                if(subArray>=k)
                    ans++;
                subArray=0;
            }
            if(subArray>=k)
            {
                ans++;
                subArray=0;
            }
        }
        if(subArray>=k)
            ans++;
        return (ans>=m);
    }
    
    
    
    int minDays(vector<int>& bloomday, int m, int k) {
        int strt=0;
        // cout<<m<<" "<<k<<" "<<m*k<<endl<<" "<<bloomday.size;
        if((long long)m*k>(long long)bloomday.size())
            return -1;
        int end=*max_element(bloomday.begin(),bloomday.end());
        cout<<strt<<" "<<end<<endl;
        while(strt<end)
        {
            long long mid=(long long)(strt+end)/2; // we are assuming mid to be our answer
            if(helper(mid,bloomday,m,k))
                end=mid;
            else
                strt=mid+1;
        }
        return end;
    }
};