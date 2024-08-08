class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        int i=0;
        int j=0;
        int cnt=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        while(i<n && j<m)
        {
            if(s[j]<g[i])
            {
                j++;
            }
            else if(s[j]>=g[i])
            {
                cnt++;
                i++;
                j++;
            }
        }
        return cnt;
        
    }
};