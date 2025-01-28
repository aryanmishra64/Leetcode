class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void f(vector<vector<int>>& graph, vector<int>& path, int i) {
        if (i == n - 1) {
            ans.push_back(path);
            return;
        }

        for (auto it : graph[i]) {
            path.push_back(it);
            f(graph, path, it);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> path = {0};
        f(graph, path, 0);
        return ans;
    }
};