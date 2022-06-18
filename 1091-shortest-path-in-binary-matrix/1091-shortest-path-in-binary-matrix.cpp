class Solution {
public:
    
    bool isValid(vector<vector<int>>& grid,int n,int i,int j)
    {
        return (i>=0 and j>=0 and i<n and j<n and grid[i][j]==0);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1)
            return -1;
        int ans=0;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=true;
        while(!q.empty())
        {
            /*
            The below 3 lines are present just to keep a count on the levels coz that is what decide the path 
            eventually. and and is incremented with every level.
            */
            ans++;
            int size=q.size();
            while(size--)
            {
            pair<int,int> pos=q.front();
            int i=pos.first;
            int j=pos.second;
            q.pop();
            if(i==n-1 and j==n-1)
                return ans;
            
            // grid[i][j]=1; // so we don't visit the same node again
            
            for(int x=i-1;x<=i+1;x++)
            {
                for(int y=j-1;y<=j+1;y++)
                {
                    if(isValid(grid,n,x,y) and !vis[x][y])
                    {
                        q.push({x,y});
                        vis[x][y]=true;
                    }
                }
            }
            }
        }
        return -1;
    }
};