class Solution {
public:
    int coinChange(vector<int>& coin, int t) {
        int n = coin.size();
        vector<vector<int>> dp(n, vector<int>(t + 1, 1e9));

        for (int j = 0; j <= t; j++) {
            if (j % coin[0] == 0) {
                dp[0][j] = j / coin[0];
            }
        }

        for (int i = 1; i < n; i++) {
            dp[i][0] = 0;
            for (int j = 1; j <= t; j++) {

                int notPick = dp[i - 1][j];
                int pick = 1e9;
                if (coin[i] <= j) {
                    pick = 1 + dp[i][j - coin[i]];
                }

                dp[i][j] = min(pick, notPick);
            }
        }

        return dp[n - 1][t] >= 1e9 ? -1 : dp[n - 1][t];
    }
};