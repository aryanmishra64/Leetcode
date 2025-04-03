class Solution {
public:
    int solve(int i,int j,string &s,string &t, vector<vector<int>>&dp){

        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=2+solve(i-1,j-1,s,t,dp);
        else {
            return dp[i][j]=max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        
        int n=s.size();
        string t=s;
         reverse(t.begin(), t.end());
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));


        int ans =solve(n-1,m-1,s,t,dp);

        return ans/2;

        
    }
};