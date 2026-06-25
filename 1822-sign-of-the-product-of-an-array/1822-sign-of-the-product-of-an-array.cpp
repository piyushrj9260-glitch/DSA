class Solution {
public:
    int signFunc(int p){
        if(p>0){
            return 1;
        }else{
            return -1;
        }
    }

    int arraySign(vector<int>& nums) {
        int sign = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                return 0;
            }
            sign *= signFunc(nums[i]);
        }
        return sign;
        
    }
};