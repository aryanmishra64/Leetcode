class Solution {
public:
    
    bool solve(string s1,string s2){

        int len1=s1.length();
        int len2=s2.length();

        if((s2.substr(0,len1)==s1) && (s2.substr(len2-len1)==s1)){
            return true;
        }
        else {
            return false;
        }



    }
   
    
    int countPrefixSuffixPairs(vector<string>& words) {
        
        int n=words.size();
        int cnt=0;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                

                if(solve(words[i],words[j])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};