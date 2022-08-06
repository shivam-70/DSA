class Solution {
public:
    string customSortString(string order, string s) {
        map<int,char> mp;
        unordered_map<char,bool> tt;
        for(int i=0;i<order.length();i++)
        {
            tt[order[i]]=true;
            mp[i]=order[i];
        }
        string a;
        string b;
        unordered_map<char,int> freq;
        for(auto it : s)
        {
            if(tt[it])
            {
                freq[it]++;
            }
            else
            {
                b+=it;
            }
        }
        // for(auto it : freq)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for(auto it : mp)
        {
            
            int cnt=freq[it.second];
            // cout<<it.second<<" "<<cnt<<endl;
            while(cnt--)
            {
                a+=it.second;
            }
        }
        return a+b;
    }
};