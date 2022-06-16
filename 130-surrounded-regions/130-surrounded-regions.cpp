class Solution {
public:
    
    void dfs(vector<vector<char>>& board,int x,int y)
    {
        if(x<0 or y<0 or x>=board.size() or y>=board[0].size())
            return;
        if(board[x][y]!='O')
            return;
        board[x][y]='*';
        dfs(board,x+1,y);
        dfs(board,x-1,y);
        dfs(board,x,y+1);
        dfs(board,x,y-1);
    }
    
    
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                dfs(board,i,0);
            }
            if(board[i][m-1]=='O')
            {
                dfs(board,i,m-1);
            }
        }
        for(int i=1;i<m-1;i++)
        {
            if(board[0][i]=='O')
            {
                dfs(board,0,i);
            }
            if(board[n-1][i]=='O')
            {
                dfs(board,n-1,i);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='*')
                    board[i][j]='O';
                else 
                    board[i][j]='X';
            }
        }
    }
};