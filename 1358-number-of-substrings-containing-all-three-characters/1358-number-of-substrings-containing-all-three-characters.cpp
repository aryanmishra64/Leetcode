class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0,count=0;
        unordered_map<char,int>mp;
        int n=s.length();
        while(j<n)
        {
            mp[s[j]]++;
            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1)
            {
                count+=(n-j);
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return count;
        
    }
};