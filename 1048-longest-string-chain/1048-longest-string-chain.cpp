class Solution {
public:
    // unordered_map<string,int> dp;
    bool isValid(string& s1,string& s2)
    {
        if(s2.length()-s1.length()!=1)
            return false;
        int i=0,j=0;
        while(i<s1.length() and j<s2.length())
        {
            if(s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        // cout<<s1<<" "<<s2<<" "<<i<<" "<<j<<endl;
        return (i==j or (i==s1.length() and j==s2.length()));
    }
    
    
    int helper(vector<string>& words,int prevIdx,vector<int>& dp)
    {
        if(dp[prevIdx]!=-1)
            return dp[prevIdx];
        int ans=1;
        for(int i=prevIdx+1;i<words.size();i++)
        {
            if(words[i].length()-words[prevIdx].length()>1)
                break;
            if(isValid(words[prevIdx],words[i]))
            {
                ans=max(ans,1+helper(words,i,dp));
            }
        }
        return dp[prevIdx]=ans;
    }
    
    int longestStrChain(vector<string>& tmp) {
        vector<int> dp(1001,-1);
        // memset(dp,-1,sizeof dp);
        sort(tmp.begin(),tmp.end(),[] (string &a,string &b) {return a.size() < b.size();});
        // for(auto it : tmp)
        //     cout<<it<<" ";
        // cout<<endl;
        int ans=1;
        for(int i=0;i<tmp.size();i++)
        {
            ans=max(ans,helper(tmp,i,dp));
        }
        return ans;
    }
};