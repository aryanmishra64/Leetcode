class Solution {
public:
    bool hasMatch(string s, string p) {
        
        int len1=s.length();
        int len2=p.length();

        int i=0;
        int j=0;

        while(i<len1 && j<len2){

            if(p[j]=='*'){
                j++;
            }

            if(s[i]==p[j]){
                i++;
                j++;
            }else {
                i++;
            }
        }
        if(i==len1 && j!=len2 && p[j]!='*'){
            return false;
        }
        else {
            return true;
        }
    }
};