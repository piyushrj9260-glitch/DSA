class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>rightMax(n),leftMin(n);

        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            rightMax[i] = maxi;
        }

        int mini = INT_MAX;
        for(int i=n-1;i>=0;i--){
            mini = min(mini,nums[i]);
            leftMin[i] = mini;
        }

        for(int i=0;i<n;i++){
            if(rightMax[i] - leftMin[i] <= k){
                return i;
            }
        }
        return -1;
    }
};