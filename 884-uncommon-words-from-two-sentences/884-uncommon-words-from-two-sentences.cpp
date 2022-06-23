class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> mp;
        string word;
        for(auto it : s1)
        {
            if(it==' ')
            {
                mp[word]++;
                word.clear();
            }
            else
            {
                word+=it;
            }
        }
        mp[word]++;
        word.clear();
        
        for(auto it : s2)
        {
            if(it==' ')
            {
                mp[word]++;
                word.clear();
            }
            else
            {
                word+=it;
            }
        }
        mp[word]++;
        word.clear();
        
        vector<string> ans;
        for(auto it : mp)
        {
            if(it.second==1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};