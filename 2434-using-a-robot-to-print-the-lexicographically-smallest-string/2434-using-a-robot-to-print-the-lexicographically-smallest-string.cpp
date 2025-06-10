class Solution {
public:
    string robotWithString(string s) {

        int n=s.size();

        vector<char>minChar(n);
        minChar[n-1]=s[n-1];

        for(int i=n-2;i>=0;i--){
            minChar[i]=min(s[i],minChar[i+1]);
        }

        string t="";
        string paper="";

        int i=0;
        while(i<n){
            t.push_back(s[i]);

            char small=(i+1 <n) ? minChar[i+1] : s[i];
            while(!t.empty() && t.back()<=small){
                paper+=t.back();
                t.pop_back();
            }
            i++;
        }

        while(!t.empty()){
            paper+=t.back();
            t.pop_back();
        }
        return paper;
        
    }
};