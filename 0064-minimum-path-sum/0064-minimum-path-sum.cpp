class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==0 && j==0){
            return grid[0][0];
        }

        if(i<0 || j<0){
            return 1e9;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int up = grid[i][j] + solve(i-1,j,grid,dp);
        int left = grid[i][j] + solve(i,j-1,grid,dp);

        dp[i][j] = min(up,left);

        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>>dp(row,vector<int>(col,-1));

        return solve(row-1,col-1,grid,dp);
    }
};