class Solution {
public:
const int MOD = 1e9 + 7;
    int solve(int i, int j, int n, int m, int curr, int k, vector<vector<int>>& nums, vector<vector<vector<int>>>& dp) {
        if (i >= n || j >= m) return 0; // Boundary check
        
        // XOR the current cell's value
        curr ^= nums[i][j];

        if (i == n-1 && j == m-1) { // If we reach the bottom-right cell
            return (curr == k) ? 1 : 0;
        }
        
        // Check memoization table
        if (dp[i][j][curr] != -1) {
            return dp[i][j][curr];
        }

        // Move right and down
        int right = solve(i, j+1, n, m, curr, k, nums, dp);
        int down = solve(i+1, j, n, m, curr, k, nums, dp);

         return dp[i][j][curr] = (right + down) % MOD; 
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int maxXor = 16; // XOR values range from 0 to 1023 (since elements ≤ 1000)
        
        // Initialize 3D DP table with -1
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(maxXor + 1, -1)));
        
        return solve(0, 0, n, m, 0, k, grid, dp); // Start with XOR = 0
    }
};
