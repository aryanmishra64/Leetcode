class Solution {
public:
    string resultingString(string s) {

        int n=s.size();
        stack<char>st;

        st.push(s[0]);

        for(int i=1;i<n;i++){

            char ch=s[i];
            
            if(st.empty()){
                st.push(ch);
            }
            else {
                char ch1=st.top();
            
            int val=ch-'a';
            int val1=ch1-'a';
            int diff=abs(val-val1);

            if(diff==1 || diff==25){
                st.pop();

            }
            else {
                st.push(ch);
            }
            }
        }
        string res="";

        while(!st.empty()){
            char ch=st.top();
            st.pop();
            res+=ch;
        }
        reverse(res.begin(),res.end());

        return res;
        
    }
};