class Solution {
public:
    int par[1001];
    
    int findPar(int n)
    {
        if(par[n]==n)
            return n;
        return par[n]=findPar(par[n]);
    }
    
    bool _union(int a ,int b)
    {
        a=findPar(a);
        b=findPar(b);
        if(a==b)
            return true;
        par[a]=b;
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        // par=vector<int>(n+1);
        for(int i=0;i<1001;i++)
        {
            par[i]=i;
        }
        vector<int> ans;
        for(auto it:edges)
        {
            int a=it[0];
            int b=it[1];
            if(_union(a,b))
                ans=it;
            else
                _union(a,b);
        }
        return ans;
    }
};