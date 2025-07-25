class Solution {
public:
    int solve(int ind, int k, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size()) {
            if (k == 0) return 0;
            else return INT_MAX;
        }
        if (k <= 0) return INT_MAX;
        if (dp[ind][k] != -1) return dp[ind][k];
        int ans = INT_MAX;
        int currxor = 0;
        for (int i = ind; i < nums.size(); i++) {
            currxor = currxor ^ nums[i];
            int curr = solve(i + 1, k - 1, nums, dp);
            ans = min(ans, max(currxor, curr));
        }
        return dp[ind][k] = ans;
    }
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        solve(0, k, nums, dp);
        return dp[0][k];
    }
};