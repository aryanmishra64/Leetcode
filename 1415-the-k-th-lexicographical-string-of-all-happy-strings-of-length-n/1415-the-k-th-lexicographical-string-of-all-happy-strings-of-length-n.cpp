class Solution {
public:
    void generateHappyStrings(int n, string &curr, vector<string> &ans) {
        if (curr.length() == n) {
            ans.push_back(curr);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {  // Iterate over characters
            if (curr.empty() || curr.back() != ch) { // Ensure consecutive different
                curr.push_back(ch);
                generateHappyStrings(n, curr, ans);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ans;
        string curr;
        generateHappyStrings(n, curr, ans);

        if (ans.size() < k) return "";
        return ans[k - 1];
    }
};
