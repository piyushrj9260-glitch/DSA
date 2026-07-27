class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int m1In = -1, m2In = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=max1){
                max2 = max1;
                max1 = nums[i];
                m2In = m1In;
                m1In = i;
            }else if(nums[i]>=max2){
                max2 = nums[i];
                m2In = i;
            }
        }
        return (nums[m1In]-1)*(nums[m2In]-1);
    }
};