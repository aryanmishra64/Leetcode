class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;


        vector<vector<int>>vis(n,vector<int>(n,1e9));

        vis[0][0]=0;

        queue<pair<int, pair<int, int>>> q;

        q.push({0,{0,0}});

        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();

            for(int drow=-1;drow<=1;drow++){
                for(int dcol=-1;dcol<=1;dcol++){
                    int nrow=row+drow;
                    int ncol=col+dcol;

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dis+1<vis[nrow][ncol]){

                        vis[nrow][ncol]=dis+1;
                        q.push({dis+1,{nrow,ncol}});
                    }

                }
            }

        }
        if(vis[n-1][n-1]==1e9) return -1;

        return vis[n-1][n-1]+1;


        
    }
};