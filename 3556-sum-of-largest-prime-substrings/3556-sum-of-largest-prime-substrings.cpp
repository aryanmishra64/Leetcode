class Solution {
public:
    bool check(string res) {
        long long n = stoll(res);
        int cnt = 0;

        if (n <= 1)
            return false;
        else {

            for (long long i = 2; i <= n / i; i++) {
            if (n % i == 0)
                return false;
        }

            if (cnt > 0)
                return false;

            // else it is prime
            else
                return true;
        }
    }
    long long sumOfLargestPrimes(string s) {

        int n = s.size();
        int ind = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                ind = i;
                break;
            }
        }
        string s1 = s.substr(ind, n);

        std::set<long long , std::greater<long long >> st;

        for (int i = 0; i < s1.size(); i++) {
            string res = "";
            for (int j = i; j < s1.size(); j++) {
                res += s1[j];

                if (check(res) == true) {
                    long long num = stoll(res);
                    st.insert(num);
                }
            }
        }

        int cnt = 0;
        long long  sum = 0;

        for (auto it : st) {
            if (cnt == 3)
                break;
            sum += it;
            cnt++;
        }
        return sum;
    }
};