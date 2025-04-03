class Solution {
public:
    int solve(vector<vector<int>>& queries, int index, int target, int queryIndex, vector<vector<int>>& dp) {
        // If target becomes 0, return the query index
        if (target == 0) return queryIndex;

        // If we have run out of queries or target becomes negative, return an invalid large value
        if (queryIndex >= queries.size() || target < 0) return queries.size() + 1;

        // If already computed, return stored result
        if (dp[target][queryIndex] != -1) return dp[target][queryIndex];

        // Skip current query (move to the next query)
        int res = solve(queries, index, target, queryIndex + 1, dp);

        // Use current query (only if index is in range)
        if (queries[queryIndex][0] <= index && index <= queries[queryIndex][1]) {
            res = min(res, solve(queries, index, target - queries[queryIndex][2], queryIndex + 1, dp));
        }

        // Store and return result
        return dp[target][queryIndex] = res;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int ans = -1;

        for (int i = 0; i < n; i++) {
            // Initialize DP table for current number (target)
            vector<vector<int>> dp(nums[i] + 1, vector<int>(queries.size(), -1));
            
            // Compute minimum query index needed to make nums[i] zero
            int minQueries = solve(queries, i, nums[i], 0, dp);
            
            // Track the maximum number of queries required for any index
            ans = max(ans, minQueries);
        }

        // If answer is greater than available queries, return -1 (impossible case)
        return (ans > queries.size()) ? -1 : ans;
    }
};
