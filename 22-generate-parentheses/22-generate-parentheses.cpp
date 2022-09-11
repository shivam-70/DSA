class Solution {
public:
    vector<string> ans;
    
    bool isValid(string s)
    {
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                cnt++;
            else if(s[i]==')')
                cnt--;
            if(cnt<0)
                return false;
        }
        return cnt==0;
    }
    
    void helper(int clos,int open,string s)
    {
        if(clos==0 and open==0)
        {
            if(isValid(s))
            {
                ans.push_back(s);
            }
            return;
        }
        if(clos>0)
        {
            helper(clos-1,open,s+')');
        }
        if(open>0)
        {
            helper(clos,open-1,s+'(');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int clos=n,open=n;
        helper(clos,open,"");
        return ans;
    }
};