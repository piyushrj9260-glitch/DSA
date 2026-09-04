class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n  = nums.size();
        vector<int>RightMax(n),LeftMin(n);

        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            RightMax[i] = maxi;
        }

        int mini = INT_MAX;
        for(int i=n-1;i>=0;i--){
            mini = min(mini,nums[i]);
            LeftMin[i] = mini;
        }

        for(int i=0;i<n;i++){
            int ans = RightMax[i]-LeftMin[i];
            if(ans <= k){
                return i;
            } 
        }
        return -1;
    }
};