class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else 
            {
                if(!st.empty())
                {
                    if(s[st.top()]=='(') st.pop();
                    else
                        st.push(i);
                }
                else st.push(i);
            }
        }
        if(st.empty())
            return s.length();
        int a=s.length(),b=0;
        while(!st.empty())
        {
            b=st.top();
            st.pop();
            ans=max(ans,a-b-1);
            a=b;
        }
        ans=max(ans,a);
        return ans;
        
    }
};