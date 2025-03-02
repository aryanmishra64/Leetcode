#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <functional>

using namespace std;

class Solution {
public:
    int solve(int left,int right,int ops,string &s,vector<vector<vector<int>>>&dp){
        if(left==right){
            return 1;
        }
        if(left>right){
            return 0;
        }
        if(dp[left][right][ops]!=-1) return dp[left][right][ops];

        int maxLen=max(solve(left+1,right,ops,s,dp),solve(left,right-1,ops,s,dp));
        int cost=min(abs(s[left]-s[right]),26-abs(s[left]-s[right]));

        if(cost<=ops){
            maxLen=max(maxLen,2+solve(left+1,right-1,ops-cost,s,dp));
        }

        return dp[left][right][ops]=maxLen;

    }


    int longestPalindromicSubsequence(string str, int maxOps) {
        
        int n=str.length();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(maxOps+1,-1)));
        return solve(0,n-1,maxOps,str,dp);
    }
};
