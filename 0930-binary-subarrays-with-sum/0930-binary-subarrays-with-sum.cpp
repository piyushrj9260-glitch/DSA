class Solution {
public:
    int binarySum(vector<int>&v,int k){
        if(k<0) return 0;

        int n = v.size();
        int l = 0;
        int r = 0;
        int cnt = 0;
        int sum = 0;

        while(r<n){
            sum += v[r];

            while(sum > k){
                sum -= v[l];
                l++;
            }

            cnt += r-l+1;
            r++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return binarySum(nums,goal) - binarySum(nums,goal-1);
    }
};