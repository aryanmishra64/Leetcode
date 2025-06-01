class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        vector<vector<int>> mpp(26);
        for (int i = 0; i < n; i++) 
            mpp[word[i] - 'a'].push_back(i);

        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; i++) {
            auto &curr = mpp[i];
            for (int j = 0; j < curr.size(); j++) {
                auto it = lower_bound(curr.begin() + j + 1, curr.end(), curr[j] + 3);
                if (it != curr.end()) {
                    intervals.emplace_back(*it, curr[j]);
                }
            }
        }

        sort(intervals.begin(), intervals.end());
        int count = 0, last = -1;
        for (auto &p : intervals) {
            if (p.second > last) {
                ++count;
                last = p.first;
            }
        }

        return count;
    }
};