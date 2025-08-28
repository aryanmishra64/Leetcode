class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int r=x+k-1;
        int c=y+k;

        for(int i=x;i<x+k/2;i++){
            
            

                for(int j=y;j<c;j++){
                    swap(grid[i][j],grid[r][j]);
                }
                r--;
                

            
        }
        return grid;
    }
};