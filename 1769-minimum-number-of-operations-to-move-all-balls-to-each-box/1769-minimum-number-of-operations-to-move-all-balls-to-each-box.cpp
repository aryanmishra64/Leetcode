class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length();
        vector<int>ans(n,0);

        int cummVal=0;
        int cummValSum=0;

        for(int i=0;i<n;i++){
            ans[i]=cummValSum;

            cummVal+= boxes[i]=='0' ? 0 : 1;
            cummValSum+=cummVal;
        }
         cummVal=0;
         cummValSum=0;
          for(int i=n-1;i>=0;i--){
            ans[i]+=cummValSum;

            cummVal+= boxes[i]=='0' ? 0 : 1;
            cummValSum+=cummVal;
        }
        return ans;

    }
};