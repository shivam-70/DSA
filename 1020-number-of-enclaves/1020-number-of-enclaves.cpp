class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i>=grid.size() or j>=grid[0].size() or i<0 or j<0)
            return;
        if(grid[i][j]!=1)
            return;
        grid[i][j]=2;
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][m-1]==1)
            {
                dfs(grid,i,m-1);
            }
            if(grid[i][0]==1)
            {
                dfs(grid,i,0);
            }
        }
        for(int i=1;i<m-1;i++)
        {
            if(grid[0][i]==1)
            {
                dfs(grid,0,i);
            }
            if(grid[n-1][i]==1)
            {
                dfs(grid,n-1,i);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    ans++;
            }
        }
        return ans;
    }
};