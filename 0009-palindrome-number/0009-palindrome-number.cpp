class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> v;
        if(x<0)
            return false;
        int n=x;
        while(n)
        {
            v.push_back(n%10);
            n/=10;
        }
        int start=0,end=v.size()-1;
        while(start<end)
        {
            if(v[start]!=v[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};