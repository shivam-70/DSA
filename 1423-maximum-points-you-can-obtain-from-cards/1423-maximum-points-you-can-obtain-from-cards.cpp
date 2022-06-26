class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int left=0,right=n-1;
        int ans=0;
        if(k==n)
        {
            for(auto it : cardPoints)
            {
                ans+=it;
            }
            return ans;
        }
        int tmpAns=0;
        while(left<k)
        {
            tmpAns+=cardPoints[left];
            left++;
        }
        left--;
        ans=max(ans,tmpAns);
        while(left>=0)
        {
            tmpAns=tmpAns-cardPoints[left]+cardPoints[right];
            left--;
            right--;
            ans=max(ans,tmpAns);
        }
        return ans;
    }
};