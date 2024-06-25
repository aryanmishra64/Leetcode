class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        
            queue<pair<int, pair<int, int>>> q;
            q.push({0,{0,0}});
        dist[0][0]=0;
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int d=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            for(int delrow=-1;delrow<=1;delrow++)
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                     if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 &&                               d+1<dist[nrow][ncol])
                     {
                         q.push({d+1,{nrow,ncol}});
                         dist[nrow][ncol]=d+1;
                     }
              
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1]+1;
        
        
        
    }
};