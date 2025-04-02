class Solution {
public:
    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i==0 || j==0){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]) return dp[i][j]=1+solve(i-1,j-1,s,t,dp);

        else return dp[i][j]=0+ max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));

        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

       int ans= solve(n,m,text1,text2,dp);

       return ans;
    }
};