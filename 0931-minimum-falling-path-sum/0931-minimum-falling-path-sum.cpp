class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up = matrix[i][j] + dp[i-1][j];

                int leftD = matrix[i][j];
                if(j-1 >= 0){
                    leftD += dp[i-1][j-1];
                }else{
                    leftD += 1e7;
                }

                int rightD = matrix[i][j];
                if(j+1 < n){
                    rightD += dp[i-1][j+1];
                }else{
                    rightD += 1e7;
                }

                dp[i][j] = min({up,leftD,rightD});
            }
        }

        int mini = dp[n-1][0];
        for(int i=1;i<n;i++){
            mini = min(mini,dp[n-1][i]);
        }

        return mini;
    }
};