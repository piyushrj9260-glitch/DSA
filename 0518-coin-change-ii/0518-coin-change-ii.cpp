class Solution {
public:
    int solve(int i,vector<int>& coins,int amount,vector<vector<int>>&dp){
        if(amount == 0) return 1;
        if(i<0 || amount<0) return 0;

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int pick = solve(i,coins,amount-coins[i],dp);

        int notPick = solve(i-1,coins,amount,dp);

        dp[i][amount] = pick + notPick;

        return dp[i][amount];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return solve(n-1,coins,amount,dp);
    }
};