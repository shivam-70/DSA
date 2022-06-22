class Solution {
public:
    bool res;
    void dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i,int j)
    {
        if(i<0 or j<0 or i>=grid1.size() or j>=grid1[0].size() or grid2[i][j]!=1)
            return;
        if(grid1[i][j]==0)
        {
            res=false;
            return;
        }
        grid2[i][j]=0;
        dfs(grid1,grid2,i+1,j);
        dfs(grid1,grid2,i,j+1);
        dfs(grid1,grid2,i-1,j);
        dfs(grid1,grid2,i,j-1);
            
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1)
                {
                    res=true;
                    dfs(grid1,grid2,i,j);
                    if(res)
                        ans++;
                }
            }
        }
        return ans;
    }
};