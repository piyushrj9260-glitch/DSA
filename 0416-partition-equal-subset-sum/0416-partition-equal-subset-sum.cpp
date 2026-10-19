class Solution {
public:
    bool solve(vector<int>& nums,int target){
        int n = nums.size();

        vector<vector<bool>>dp(n,vector<bool>(target+1,false));

        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }

        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        for(int i=1;i<n;i++){
            for(int t=1;t<=target;t++){
                bool notTake = dp[i-1][t];
                bool take = false;
                if(t >= nums[i]){
                    take = dp[i-1][t-nums[i]];
                }

                dp[i][t] = take || notTake;
            }
        }
        return dp[n-1][target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2 != 0){
            return false;
        }

        return solve(nums,sum/2);
    }
};