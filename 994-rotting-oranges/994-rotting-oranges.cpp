class Solution {
public:
    
    bool isValid(vector<vector<int>>& grid,int i,int j,int n)
    {
        if(i<0 or j<0 or i>=n or j>=grid[0].size() or grid[i][j]==2 or grid[i][j]==0)
            return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                    cnt++;
            }
        }
        int ans=0;
        if(!cnt)
            return 0;
        while(!q.empty())
        {
            ans++;
            int size=q.size();
            
            while(size--)
            {
                pair<int,int> pos=q.front();
                q.pop();
                int i=pos.first;
                int j=pos.second;
                if(isValid(grid,i+1,j,n))
                {
                    q.push({i+1,j});
                    grid[i+1][j]=2;
                }
                if(isValid(grid,i,j+1,n))
                {
                    q.push({i,j+1});
                    grid[i][j+1]=2;
                }
                if(isValid(grid,i-1,j,n))
                {
                    q.push({i-1,j});
                    grid[i-1][j]=2;
                }
                if(isValid(grid,i,j-1,n))
                {
                    q.push({i,j-1});
                    grid[i][j-1]=2;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans-1;
    }
};