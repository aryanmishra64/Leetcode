class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    q.push({i,j});
                }
            }
        }

        int maxi=0;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;

            q.pop();
            int drow[]={-1,0,+1,0};
            int dcol[]={0,+1,0,-1};
            int totalfish=grid[row][col];

            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]>0 && !vis[nrow][ncol]){

                    totalfish+=grid[nrow][ncol];
                    
                    vis[nrow][ncol]=1;

                }

            }
            maxi=max(maxi,totalfish);
        }
        return maxi;
    }
};