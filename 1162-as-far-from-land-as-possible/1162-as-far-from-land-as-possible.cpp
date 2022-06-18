class Solution {
public:
    /*
    we find our land cells and put surrounding water cells in the queue. We mark water cells as visited and 
    continue the expansion from land cells until there are no more water cells left. In the end, the number 
    of steps in DFS is how far can we go from the land.
    */
    
    int maxDistance(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int ones=0,zeroes=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1){
                    ones++;
                    q.push({i-1,j});
                    q.push({i+1,j});
                    q.push({i,j+1});
                    q.push({i,j-1});
                }
                else{
                    zeroes++;
                }
            }
        }
        if(!zeroes or !ones)
            return -1;
        
        
        while(!q.empty())
        {
            ans++;
            int size=q.size();
            while(size--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i>=0 and j>=0 and i<n and j<n and grid[i][j]==0)
                {
                    grid[i][j]=ans;
                    q.push({i-1,j});
                    q.push({i+1,j});
                    q.push({i,j+1});
                    q.push({i,j-1});
                }
            }
        }
        
        
        if(ans==1)
            return -1;
        else
            return ans-1;
    }
};