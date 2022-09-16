class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(auto ch : s)
        {
            if(ch=='(')
            {
                st.push(0);
            }
            else
            {
                int tmp=st.top();
                st.pop();
                if(tmp==0)
                {
                    st.top()+=1;
                }
                else
                {
                    st.top()+=2*tmp;
                }
            }
        }
        return st.top();
    }
};