class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int c=1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(c%2 != 0){
                sum = sum+nums[i];
                c++;
            }else{
                sum = sum-nums[i];
                c++;
            }
        }
        return sum;
    }
};