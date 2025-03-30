class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();

        vector<int>mp(26,-1);
        vector<int>result;

        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            mp[idx]=i;
        }

        int i=0;
        while(i<n){
            int end=mp[s[i]-'a'];
            int j=i;

         

            while(j<end){
                end=max(end,mp[s[j]-'a']);
                j++;
            }

            result.push_back(j-i+1);
            i=j+1;

        }
        return result;
    }
};