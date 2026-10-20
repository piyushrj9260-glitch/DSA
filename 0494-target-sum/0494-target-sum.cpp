
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for (int x : nums) {
            sum += x;
        }

        // Impossible to reach target
        if (abs(target) > sum) {
            return 0;
        }

        // Required subset sum must be an integer
        if ((sum + target) % 2 != 0) {
            return 0;
        }

        int k = (sum + target) / 2;

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        // Empty subset gives sum 0
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        // Handle the first element, including zero
        dp[0][0] = (nums[0] == 0) ? 2 : 1;

        if (nums[0] != 0 && nums[0] <= k) {
            dp[0][nums[0]] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= k; t++) {
                int notPick = dp[i - 1][t];

                int pick = 0;
                if (nums[i] <= t) {
                    pick = dp[i - 1][t - nums[i]];
                }

                dp[i][t] = pick + notPick;
            }
        }

        return dp[n - 1][k];
    }
};
