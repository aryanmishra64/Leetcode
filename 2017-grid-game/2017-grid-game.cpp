class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstrow=accumulate(begin(grid[0]),end(grid[0]),0LL);

        long long secondrem=0;

        long long mini=LONG_LONG_MAX;

        for(int col=0;col<grid[0].size();col++){

            firstrow-=grid[0][col];

            long long robot2=max(firstrow,secondrem);

            mini=min(mini,robot2);

            secondrem+=grid[1][col];
        }
        return mini;
    }
};