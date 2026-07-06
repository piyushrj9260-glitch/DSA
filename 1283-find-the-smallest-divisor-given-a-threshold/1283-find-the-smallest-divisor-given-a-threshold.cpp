class Solution {
public:

    int findMax(vector<int>&nums){
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int s = 1;
        int e = findMax(nums);
        int ans = INT_MAX;
        while(s<=e){
            int mid = s+(e-s)/2;
            int totalSum = 0;
            for(int i=0;i<n;i++){
                totalSum += ceil((double)nums[i]/(double)mid);
            }
            if(totalSum <= threshold){
                ans = min(ans,mid);
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};