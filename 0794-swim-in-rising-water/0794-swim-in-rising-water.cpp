// Disjoint Set (Union-Find) class to manage connected components
class DisjointSet {
public:
    vector<int> rank, parent, size;

    // Constructor to initialize the Disjoint Set with n elements
    DisjointSet(int n) {
        rank.resize(n + 1, 0);       // Initialize rank to 0
        parent.resize(n + 1);        // Initialize parent array
        size.resize(n + 1, 1);       // Initialize size of each component to 1
        for (int i = 0; i <= n; i++) {
            parent[i] = i;           // Initially, each node is its own parent
        }
    }

    // Find the representative (root) of the set that node belongs to
    int findUPar(int node) {
        if (node == parent[node])     // If the node is its own parent, return it
            return node;
        return parent[node] = findUPar(parent[node]);   // Path compression
    }

    // Union by rank to combine two sets
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);  // Find the root of u
        int ulp_v = findUPar(v);  // Find the root of v

        if (ulp_u == ulp_v)       // If u and v are already in the same set, do nothing
            return;

        // Union by rank (smaller tree gets attached under the larger one)
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;  // Increase rank when both sets have equal rank
        }
    }

    // Union by size to merge the smaller set under the larger one
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);  // Find the root of u
        int ulp_v = findUPar(v);  // Find the root of v

        if (ulp_u == ulp_v)       // If u and v are already in the same set, do nothing
            return;

        // Union by size (smaller set gets merged under the larger set)
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];  // Update size
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];  // Update size
        }
    }
};

// Main solution class to compute the minimum time to swim
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();  // Get the size of the grid
        vector<pair<int, pair<int, int>>> edges;  // To store the edges (water level, node1, node2)
        DisjointSet ds(N * N);  // Initialize Disjoint Set for N x N grid

        // Build edges between adjacent cells in the grid
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // Check the cell below the current cell (downward edge)
                if (i + 1 < N) {
                    edges.push_back({max(grid[i][j], grid[i + 1][j]), {i * N + j, (i + 1) * N + j}});
                }
                // Check the cell to the right of the current cell (rightward edge)
                if (j + 1 < N) {
                    edges.push_back({max(grid[i][j], grid[i][j + 1]), {i * N + j, i * N + j + 1}});
                }
            }
        }

        // Sort edges by water level in ascending order
        sort(edges.begin(), edges.end());

        // Process the edges and unite connected cells
        for (auto& edge : edges) {
            int t = edge.first;  // Water level for this edge
            int u = edge.second.first;  // First cell in the edge
            int v = edge.second.second;  // Second cell in the edge

            // Union the two cells if they are not already connected
            ds.unionBySize(u, v);

            // Check if the top-left (0) and bottom-right (N*N - 1) cells are connected
            if (ds.findUPar(0) == ds.findUPar(N * N - 1)) {
                return t;  // If connected, return the current water level
            }
        }

        return 0;  // Return 0 if no path exists (though a path will always exist in this problem)
    }
};
