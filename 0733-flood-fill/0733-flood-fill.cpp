class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
          
        int n=image.size();
        int m=image[0].size();
       vector<vector<int>> vis(n, vector<int>(m, 0)); 
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=color;
        int val=image[sr][sc];
        
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            
            int drow[4] = {0, 0, 1, -1};
           int dcol[4] = {1, -1, 0, 0};
            q.pop();
           
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==val && vis[nrow][ncol]!=color) 
         {
              q.push({nrow,ncol});
              vis[nrow][ncol]=color;
          }
               
            }
            
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==color)
                {
                    image[i][j]=color;
              }
            }
        }
        return image;
    }
};