class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));

        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,pair<int,int>>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int val=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();

            int drow[]={-1,0,+1,0};
            int dcol[]={0,+1,0,-1};

            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] ){
                    q.push({val+1,{nrow,ncol}});
                    ans[nrow][ncol]=val+1;
                    vis[nrow][ncol]=1;
                }
            }
        }
        return ans;

    }
};