class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        unordered_map<int,int>mpp;

        for(int i=0;i<arr.size();i++){
            int val=arr[i];
            mpp[val]=i;
        }

        int minIndex=INT_MAX;

        for(int row=0;row<n;row++){
            int last=INT_MIN;

            for(int col=0;col<m;col++){
                int val=mat[row][col];
                int idx=mpp[val];
                last=max(last,idx);
            }
            minIndex=min(minIndex,last);

        }
        for(int col=0;col<m;col++){
            int last=INT_MIN;

            for(int row=0;row<n;row++){
                int val=mat[row][col];
                int idx=mpp[val];
                last=max(last,idx);
            }
            minIndex=min(minIndex,last);

        }
        return minIndex;
    }
};