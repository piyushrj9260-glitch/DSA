class Solution {
public:
    int solve(int indx,vector<int>&nums,vector<int>&dp){
        if(indx == 0){
            return nums[0];
        }
        if(indx < 0){
            return 0;
        }

        if(dp[indx] != -1){
            return dp[indx];
        }

        int pick = nums[indx] + solve(indx-2,nums,dp);

        int notPick = solve(indx-1,nums,dp);

        dp[indx] = max(pick,notPick);

        return dp[indx];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);
    }
};