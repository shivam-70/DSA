class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back()<=target) return letters.front();
         int strt=0;
        int end=letters.size()-1;
        int ans=-1;
        
        while(strt<=end)
        {
            int mid=strt+(end-strt)/2;
            if(letters[mid]<=target)
            {
                strt=mid+1;
            }
            else
            {
                ans=mid;
                end=mid-1;
                
            }
        }
        
        return letters[ans%letters.size()];
        // return 'x';
    }
};