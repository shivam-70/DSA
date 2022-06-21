class Solution {
public:
    int par[26];
    
    int findPar(int n)
    {
        if(par[n]==n)
            return n;
        return par[n]=findPar(par[n]);
    }
    
    void _union(int a,int b)
    {
        a=findPar(a);
        b=findPar(b);
        if(a!=b)
            par[a]=b;
    }
    
    bool equationsPossible(vector<string>& v) {
        int n=v.size();
        memset(par,-1,sizeof par);
        for(int i=0;i<26;i++)
        {
            par[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            if(v[i][1]=='=')
            {
                int a=v[i][0]-'a';
                int b=v[i][3]-'a';
                _union(a,b);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(v[i][1]=='!')
            {
                int a=findPar(v[i][0]-'a');
                int b=findPar(v[i][3]-'a');
                
                if(a==b){
                    cout<<v[i]<<endl;
                    return false;
                }
            }
        }
        return true;
    }
};