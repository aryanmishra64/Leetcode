class Solution {
public:
    int solve(string s,unordered_map<char,int>&mpp){

        int len=s.length();
        int ans=1;

        for(int i=0;i<len;i++){
            char ch=s[i];

            if(mpp.find(ch)!=mpp.end()){
                ans=0;
                break;


            }
        }
        return ans;
    }
    int canBeTypedWords(string text, string brokenLetters) {

        int n=text.length();
        int ind=0;

        unordered_map<char,int>mpp;
        int ans=0;

        for(auto it:brokenLetters){
            mpp[it]++;
        }

        string s="";

        for(int i=0;i<n;i++){

            char ch=text[i];
            s+=ch;

            if(ch==' '){
               ans+= solve(s,mpp);
               s="";

            }
            

            


        }
        if(solve(s,mpp)){
                ans++;
            }
        return ans;

        
        

    }
};