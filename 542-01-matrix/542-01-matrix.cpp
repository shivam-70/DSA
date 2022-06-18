class Solution {
public:
    
    bool isValid(vector<vector<int>>& mat,int x,int y,int n,int m)
    {
        if(x<0 or y<0 or x>=n or y>=m)
            return false;
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
		// using queue to store position of elements whose answer we know, to use it to derive others' distances
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX)); // initializing result matrix with max value (distance)
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    ans[i][j]=0;// distance of 0 from nearest 0 will be 0 (itself)
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        
        while(!q.empty())
        {
			// position of element whose result is known
            int curX=q.front().first;
            int curY=q.front().second;
            q.pop();
            
            for(auto it : dir)// traversing in all possible direction
            {
                int x=curX+it.first;
                int y=curY+it.second;
                if(isValid(mat,x,y,n,m))
                {
                    if(ans[x][y]>ans[curX][curY]+1)// update the distance if previous distance is more than distance of current element + 1 (bcoz. we can move only 1 step at a time)
                    {
                        ans[x][y]=ans[curX][curY]+1;
                        q.push({x,y});// adding result to queue to use to derive other distances
                    }
                }
            }
        }
        return ans;
    }
};