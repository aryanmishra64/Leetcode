class Solution {
public:
    int solve(int col,int n,vector<string>&board,vector<int>&leftRow,vector<int>&upper,vector<int>&lower,int &c)
    {
        if(col==n)
        {
           c++;
        } 
        for(int row=0;row<n;row++)
        {
            if(leftRow[row]==0&&lower[row+col]==0 && upper[n-1+col-row]==0)
            {
                board[row][col]='Q';
                leftRow[row]=1;
                lower[row+col]=1;
                upper[n-1+col-row]=1;
                solve(col+1,n,board,leftRow,upper,lower,c);
                board[row][col]='.';
                leftRow[row]=0;
                lower[row+col]=0;
                upper[n-1+col-row]=0;
            }
        }
        return c;
    }
    int totalNQueens(int n) 
    {
        vector<string>board(n);
        string s(n,'.');
        for(int i=1;i<n;i++)
        {
            board[i]=s;
        }
        vector<int>leftRow(n,0),upper(2*n-1,0),lower(2*n-1,0);
        int c=0;
        return solve(0,n,board,leftRow,upper,lower, c);
    }
};