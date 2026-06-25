class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int>uni;
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(nums[i] == nums[j]){
                    cnt++;
                }
            }
            if(cnt == 1){
                sum = sum + nums[i];
            }
       }
       return sum;
    }
};