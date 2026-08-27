class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;

        // XOR all numbers
        for(int n : nums)
            x ^= n;

        // Rightmost set bit
       long long int bit = x & -x;

        int a = 0, b = 0;

        // Divide numbers into two groups
        for(int n : nums) {

            if(n & bit)
                a ^= n;
            else
                b ^= n;
        }

        return {a, b};
    }
};