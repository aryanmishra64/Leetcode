class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int>mpp;
        int l=0;
        int r=0;
        int cnt=0;
        int minLen=INT_MAX;
        int sIndex=-1;
        
        for(int i=0;i<t.size();i++)
        {
            mpp[t[i]]++;
        }
        while(r<s.size())
        {
            if(mpp[s[r]]>0)
            {
                cnt=cnt+1;
            }
            mpp[s[r]]--;
            
            while(cnt==t.size())
            {
                if(r-l+1<minLen)
                {
                    minLen=r-l+1;
                    sIndex=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0)
                {
                    cnt=cnt-1;
                }
                l++;
            }
            r++;
        }
        return sIndex==-1 ? "" :s.substr(sIndex,minLen);
            
    }
};