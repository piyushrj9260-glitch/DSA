class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int XOR = 0;
        for(int i=0;i<=n;i++){
            XOR = XOR ^ i;
        }
        int XOR1 = 0;
        for(int i=0;i<n;i++){
            XOR1 = XOR1 ^ nums[i];
        }
        return XOR ^ XOR1;
    }
};