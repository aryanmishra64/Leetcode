class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days; // If no meetings, all days are free.

        sort(meetings.begin(), meetings.end()); // Step 1: Sort meetings by start time
        
        int ans = 0, last_end = 0;

        for (auto& m : meetings) {
            int start = m[0], end = m[1];

            // Count free days before this meeting starts
            if (start > last_end + 1) {
                ans += (start - last_end - 1);
            }

            // Update the last end day
            last_end = max(last_end, end);
        }

        // Count free days after the last meeting
        if (last_end < days) {
            ans += (days - last_end);
        }

        return ans;
    }
};
