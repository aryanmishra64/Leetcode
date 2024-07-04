class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>matrix(n,vector<int>(n,INT_MAX));
        
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            matrix[u][v]=wt;
            matrix[v][u]=wt;
            
        }
        for (int i = 0; i < n; ++i) {
            matrix[i][i] = 0;  
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    	if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
						continue;
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
       	int cntCity = n;
		int cityNo = -1;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && matrix[i][j]<=distanceThreshold)
                {
                    cnt++;
                }
                
            }
            if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = i;
			}
        }
        
        
        return cityNo;
        
    }
};