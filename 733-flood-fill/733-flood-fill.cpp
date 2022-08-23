class Solution {
public:
    
    bool isValid(vector<vector<int>>& image,int x,int y,vector<vector<int>>& vis,int sr,int sc)
    {
        if(x<0 or y<0 or x>=image.size() or y>=image[0].size())
        {
            return false;
        }
        if(vis[x][y] or image[x][y]!=image[sr][sc])
            return false;
        return true;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(isValid(image,x+1,y,vis,sr,sc))
            {
                q.push({x+1,y});
                vis[x+1][y]=1;
                image[x+1][y]=color;
            }
            if(isValid(image,x,y+1,vis,sr,sc))
            {
                q.push({x,y+1});
                vis[x][y+1]=1;
                image[x][y+1]=color;
            }
            if(isValid(image,x-1,y,vis,sr,sc))
            {
                q.push({x-1,y});
                vis[x-1][y]=1;
                image[x-1][y]=color;
            }
            if(isValid(image,x,y-1,vis,sr,sc))
            {
                q.push({x,y-1});
                vis[x][y-1]=1;
                image[x][y-1]=color;
            }
        }
        image[sr][sc]=color;
        // for(auto it : vis)
        // {
        //     for(auto itr : it)
        //     {
        //         cout<<itr<<" ";
        //     }
        //     cout<<endl;
        // }
        return image;
    }
};