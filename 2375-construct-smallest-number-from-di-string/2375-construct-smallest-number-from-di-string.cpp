class Solution {
public:
    bool solve(int idx,int n,string &curr,vector<bool>&used,string &pattern,string &ans){
        if(idx>=n+1) {
            ans=curr;
            return true;
        }

        for(char digit='1';digit<='9';digit++){
            if(used[digit]==true) continue;

            if(!curr.empty() && ((pattern[idx-1]=='I' && curr.back()>=digit) || (pattern[idx-1]=='D' && curr.back()<=digit))){
                continue;
            }

            curr+=digit;
            used[digit]=true;

            if(solve(idx+1,n,curr,used,pattern,ans)==true){
                return true;
            }

            used[digit]=false;
            curr.pop_back();

        }
        return false;

        


    }



    string smallestNumber(string pattern) {
        int n=pattern.length();

        vector<bool>used(10,false);

        string ans;
        string curr;
        solve(0,n,curr,used,pattern,ans);

        return ans;
    }
};