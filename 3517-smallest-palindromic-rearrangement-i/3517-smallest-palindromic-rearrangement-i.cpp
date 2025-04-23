class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        // Count frequencies of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<char> result(n);
        int left = 0, right = n - 1;
        char midChar = 0;

        for (int i = 0; i < 26; ++i) {
            char ch = i + 'a';

            // If frequency is odd
            if (freq[i] % 2 == 1) {
                if (midChar == 0) {
                    midChar = ch;  // Use odd frequency char for the middle
                }
                freq[i]--;  // Leave one for the middle, use rest in pairs
            }

            // Place characters symmetrically
            while (freq[i] > 0) {
                result[left++] = ch;
                result[right--] = ch;
                freq[i] -= 2;
            }
        }

        // Place the mid character if any
        if (midChar != 0) {
            result[n / 2] = midChar;
        }

        return string(result.begin(), result.end());
    }
};
