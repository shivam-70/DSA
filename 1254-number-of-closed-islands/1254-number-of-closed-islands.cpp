class Solution {
public:
    
    bool dfs(vector<vector<int>>& grid,int x,int y)
    {
        if(x<0 or y<0 or x>=grid.size() or y>=grid[0].size())
            return false;
        if(grid[x][y]==1)
            return true;
        grid[x][y]=1;
        bool d1,d2,d3,d4;
        d1=dfs(grid,x+1,y);
        d2=dfs(grid,x-1,y);
        d3=dfs(grid,x,y+1);
        d4=dfs(grid,x,y-1);
        return (d1 and d2 and d3 and d4);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0 and dfs(grid,i,j))
                    ans++;
            }
        }
        return ans;
    }
};