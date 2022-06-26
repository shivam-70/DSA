class Solution {
public:
    
    // in other words, print minimum subset difference
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        for(auto it : stones)
            sum+=it;
        bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0 and j==0)
                {
                    dp[i][j]=true;
                    continue;
                }
                if(i==0)
                {
                    dp[i][j]=false;
                    continue;
                }
                if(j==0)
                {
                    dp[i][j]=true;
                    continue;
                }
                if(stones[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j] or dp[i-1][j-stones[i-1]];
            }
        }
        for(int i=sum/2;i>=0;i--)
        {
            if(dp[n][i]==true)
            {
                return sum-2*i;
            }
        }
        return 0;
    }
};