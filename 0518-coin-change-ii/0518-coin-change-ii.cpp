class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
         vector<vector<long>> dp(n, vector<long>(amount + 1, 0)); 

    for (int i = 0; i <= amount; i++) {
        if (i % coins[0] == 0)
            dp[0][i] = 1;
        
    }

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= amount; target++) {
            long notTaken = dp[ind - 1][target];

            long taken = 0;
            if (coins[ind] <= target)
                taken = dp[ind][target - coins[ind]];

            dp[ind][target] = notTaken + taken;
        }
    }

    return dp[n - 1][amount];
    }
};