class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;

        for (int x : nums)
            xr ^= x;

        if (xr != 0)
            return nums.size();

        // Total XOR is 0.
        // Remove one non-zero element.
        for (int x : nums) {
            if (x != 0)
                return nums.size() - 1;
        }

        // All elements are 0, so every non-empty subsequence has XOR 0.
        return 0;
    }
};