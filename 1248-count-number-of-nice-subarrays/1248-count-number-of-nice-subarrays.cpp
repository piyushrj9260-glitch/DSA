class Solution {
public:
    int binarySum(vector<int>&v,int k){
        if(k<0) return 0;

        int n = v.size();
        int cnt = 0;
        int sum = 0;
        int l = 0;
        int r = 0;

        while(r<n){
            sum += (v[r]%2);
            while(sum > k){
                sum -= v[l]%2;
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return binarySum(nums,k) - binarySum(nums,k-1);
    }
};