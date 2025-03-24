#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    // Function to count distinct common elements
    int intersect(const unordered_set<int>& setA, const unordered_set<int>& setB) {
        int count = 0;
        for (int num : setA) {
            if (setB.count(num)) {
                count++;
            }
        }
        return count;
    }

    // BFS traversal to count components
    void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    // Function to count connected components
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<vector<int>> adj(n);
        vector<unordered_set<int>> propertySets(n);

        // Convert each row to a set for O(1) lookups
        for (int i = 0; i < n; i++) {
            propertySets[i] = unordered_set<int>(properties[i].begin(), properties[i].end());
        }

        // Build adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (intersect(propertySets[i], propertySets[j]) >= k) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Count connected components using BFS
        vector<bool> visited(n, false);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(i, adj, visited);
                components++;
            }
        }

        return components;
    }
};
