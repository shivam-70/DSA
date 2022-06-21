class Solution {
public:
    vector<int> par;
    int findPar(int n)
    {
        if(par[n]==n)
            return n;
        return par[n]=findPar(par[n]);
    }
    
    bool _union(int a,int b)
    {
        a=findPar(a);
        b=findPar(b);
        if(a==b)
            return false;
        par[b]=a;
        return true;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        par=vector<int>(n);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1])
                {
                    if(_union(i,j))
                        ans++;
                }
            }
        }
        return ans;
    }
};