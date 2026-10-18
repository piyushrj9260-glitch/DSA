class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = 1;
        unordered_set<int>mp;

        for(int i=1;i<n;i++){
            int sum = nums[i]+nums[i-1];
            if(mp.contains(sum)) return true;
            else mp.insert(sum);
        }
        return false;
    }
};