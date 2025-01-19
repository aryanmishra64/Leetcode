class Solution {
public:
    typedef pair<int, pair<int, int>> PP; // Pair representing {height, {row, col}}

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(); // Number of rows
        int n = heightMap[0].size(); // Number of columns

        // If the grid is too small, no water can be trapped
        if (m < 3 || n < 3) return 0;

        // Min-heap to store the boundary cells
        priority_queue<PP, vector<PP>, greater<>> pq;

        // Visited array to track cells that are already processed
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add all boundary cells to the priority queue
        for (int row = 0; row < m; row++) {
            for (int col : {0, n - 1}) {
                pq.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }
        for (int col = 0; col < n; col++) {
            for (int row : {0, m - 1}) {
                pq.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        int water = 0; // Variable to accumulate trapped water
        int drow[] = {0, 0, 1, -1}; // Directions for row (right, left, down, up)
        int dcol[] = {1, -1, 0, 0}; // Directions for column (right, left, down, up)

        // Process the priority queue
        while (!pq.empty()) {
            int ht = pq.top().first; // Current cell's height
            int row = pq.top().second.first; // Row of the current cell
            int col = pq.top().second.second; // Column of the current cell
            pq.pop();

            // Explore the 4 neighbors
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                // Check if the neighbor is within bounds and not visited
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol]) {
                    // Calculate the water trapped, if any
                    water += max(ht - heightMap[nrow][ncol], 0);

                    // Update the neighbor's height to the maximum of the current cell height and its own height
                    pq.push({max(ht, heightMap[nrow][ncol]), {nrow, ncol}});

                    // Mark the neighbor as visited
                    visited[nrow][ncol] = true;
                }
            }
        }
        return water; // Return the total trapped water
    }
};
