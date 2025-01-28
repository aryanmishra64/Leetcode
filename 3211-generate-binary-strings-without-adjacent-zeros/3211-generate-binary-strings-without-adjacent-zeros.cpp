
class Solution {
public:
    void generateValidStrings(int n, string current, vector<string>& result) {
    if (current.length() == n) {
        result.push_back(current);
        return;
    }
 
    if (current.empty() || current.back() == '1') {
        generateValidStrings(n, current + '0', result);
        generateValidStrings(n, current + '1', result);
    }

    else if (current.back() == '0') {
        generateValidStrings(n, current + '1', result);
    }
}
    vector<string> validStrings(int n) {
         vector<string> result;
         generateValidStrings(n, "", result);
         return result;
    }
};