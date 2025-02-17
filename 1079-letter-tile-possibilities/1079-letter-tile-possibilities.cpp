class Solution {
public:
    

    void solve(int n,string& tiles, vector<bool>& used, unordered_set<string>& result, string &curr) {
        result.insert(curr);

        for(int i = 0; i < n; i++) {
            if(used[i])
                continue;

            curr.push_back(tiles[i]);
            used[i] = true;

            solve(n,tiles, used, result, curr);

            used[i] = false;
            curr.pop_back();
        }
    }

    int numTilePossibilities(string tiles) {
       int n = tiles.length();
        vector<bool> used(n, false);
        unordered_set<string> result;
        string curr = "";

        solve(n,tiles, used, result, curr);

        return result.size()-1;
    }
};
