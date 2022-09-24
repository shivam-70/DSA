class Solution {
public:
    bool isPalindrome(string s) {
        // int n=s.length();
        string tmp;
        for(auto it : s)
        {
            if(isalpha(it) or isdigit(it))
                tmp.push_back(tolower(it));
        }
        int n=tmp.length();
        int strt=0,end=n-1;
        cout<<tmp<<endl;
        while(strt<end)
        {
            if(tmp[strt]!=tmp[end])
                return false;
            strt++;
            end--;
        }
        
        return true;
    }
};