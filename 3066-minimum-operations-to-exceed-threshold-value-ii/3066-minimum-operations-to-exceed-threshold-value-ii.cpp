class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int> > pq; 

        int n=nums.size();

        int cnt=0;

        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }

        while(pq.top()<k){

            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            int val=min(a, b) * 2 + max(a, b);
            pq.push(val);
            cnt++;
        }
        return cnt;
    }
};