class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int n= grid.size(), m = grid[0].size();
        queue<pair<pair<int, int>,int>> rotten;
        int vis[n][m];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
             
                if(grid[i][j] == 2) 
                {
                    rotten.push({{i,j},0});
                    vis[i][j]=2;
                }
                else {
                    vis[i][j]=0;
                }
                
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int tm=0;
        
        while(!rotten.empty()){
            
            
                int r = rotten.front().first.first; int c = rotten.front().first.second;
            int t=rotten.front().second;
              tm=max(tm,t);
                rotten.pop();
            
                for(int i = 0; i < 4; ++i){
                    int nx = r + dx[i], ny = c + dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]!=2 && grid[nx][ny]==1)
                    {
                        rotten.push({{nx,ny},t+1});
                        vis[nx][ny]=2;
                    }
                    
                }
            
            
        }
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(vis[i][j]!=2 && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        
        return tm;
    
    }
};