class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        if(n==1){
            if(s[0]=='0'){
                return 0;
            }
            else {
                return 1;
            }
        }
        vector<int>zeroes(n,0);
        int zeros=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zeros++;
            }
            else {
                if(zeros!=0) zeroes[j++]=zeros;
                zeros=0;
            }
        }
        if(zeros) zeroes[j++]=zeros;
        int one=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                one++;
            }
        }
        int ans=one;

        for(int i=1;i<j;i++){
            ans=max(ans,one+zeroes[i-1]+zeroes[i]);
        }
        return ans;       
    }
};