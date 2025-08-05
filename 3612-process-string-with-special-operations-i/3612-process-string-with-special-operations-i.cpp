class Solution {
public:
    string processStr(string s) {

        string ans="";

        for(int i=0;i<s.length();i++){
            char ch=s[i];

            if(ch=='*' && (ans.length()>=1)){
                ans.pop_back();
            }
            else if(ch=='#'){
                ans+=ans;
            }
            else if(ch=='%' && (ans.length()>=1)){
                reverse(ans.begin(),ans.end());
            }
            else if(ch!='*' && ch!='#' && ch!='%'){
                ans+=ch;
            }
        }
        return ans;

        
    }
};