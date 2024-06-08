class Solution {
public:
   vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        // distance matrix initialized to a large number
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        // queue for BFS
        queue<pair<int, int>> q;

        // Traverse the matrix and initialize the queue with all '0' positions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // Directions for moving up, right, down, left
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        // Perform BFS from all '0' positions
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Check all 4 neighbors
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                // Check for valid cell and if the new distance is smaller
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    if (dist[nrow][ncol] > dist[row][col] + 1) {
                        dist[nrow][ncol] = dist[row][col] + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        // Return the distance matrix
        return dist;
    }
};