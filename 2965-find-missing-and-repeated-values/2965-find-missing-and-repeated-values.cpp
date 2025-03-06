class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> mpp;  // Frequency map
        int repeated = -1, missing = -1;

        // Count occurrences of each number in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mpp[grid[i][j]]++;
                if (mpp[grid[i][j]] == 2) {
                    repeated = grid[i][j];  // Found the repeated number
                }
            }
        }

        // Find the missing number (1 to n*n)
        for (int i = 1; i <= n * n; i++) {
            if (mpp.find(i) == mpp.end()) {  // Number not found in grid
                missing = i;
                break;
            }
        }

        return {repeated, missing};
    }
};
