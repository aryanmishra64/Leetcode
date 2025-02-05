class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        int n=s1.length();

        vector<int>hash1(26,0);
        vector<int>hash2(26,0);
        for(int i=0;i<n;i++){
            hash1[s1[i]-'a']++;
            hash2[s2[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(hash1[i]!=hash2[i]){
                return false;
            }
        }

        int cnt=0;
        int j=0;

        while(j<n){
            if(s1[j]!=s2[j]){
                cnt++;
            }
            j++;
        }

        if(cnt==0 || cnt==2){
            return true;
        }
        else {
            return false;
        }
    }
};