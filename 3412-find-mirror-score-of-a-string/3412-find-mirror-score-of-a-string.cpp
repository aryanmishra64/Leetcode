class Solution {
public:
    long long calculateScore(string s) {
        
        int n=s.length();
        unordered_map<char,int>mpp;

        mpp[s[0]]=0;
        long long res=0;

        for(int i=1;i<n;i++){
            char ch=s[i];

           

            char mirror = 'z' - (ch - 'a');

            if(mpp.find(mirror)!=mpp.end()){
                
                 res += i - mpp[mirror];
                mpp.erase(mirror);
            }

            else{
                mpp[ch]=i;
            }


        }
        return res;
    }
};