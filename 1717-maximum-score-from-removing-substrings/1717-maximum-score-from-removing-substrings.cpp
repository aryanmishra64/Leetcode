class Solution {
public:
    string solve(string &s,string &mat){

        stack<char>st;
        for(char &ch:s){
            if(ch==mat[1] && !st.empty() && st.top()==mat[0]){
                st.pop();
            }else {
                st.push(ch);
            }
        }
        string temp;
        while(!st.empty()){
            char c=st.top();
            st.pop();
            temp+=c;
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    
    int maximumGain(string s, int x, int y) {
        int n=s.length();
        int score=0;

        string maxstr=(x>y)?"ab" : "ba";
       string minstr = (maxstr == "ab") ? "ba" : "ab";

        string temp=solve(s,maxstr);
        
        int L=temp.length();
        int rem=n-L;

        score+=(rem/2)*max(x,y);

        string temp2=solve(temp,minstr);
        int len=temp2.length();
        int rem2=L-len;
        score+=(rem2/2)*min(x,y);


       return score;
        

    }
};