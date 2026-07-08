class Solution {
public:
    int findA(vector<int>&nums,int m){
        int n = nums.size();
        int A = 1;
        int t = 0;
        for(int i=0;i<n;i++){
            if(t+nums[i]<=m){
                t+=nums[i];
            }else{
                A++;
                t = nums[i];
            }
        }
        return A;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) return -1;
        int s = *max_element(nums.begin(),nums.end());
        int e = accumulate(nums.begin(),nums.end(),0);
        while(s<=e){
            int mid = s+(e-s)/2;
            int a = findA(nums,mid);
            if(a>k){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return s;
    }
};