class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = 1;
        unordered_map<int,int>mp;

        while(r < n){
            mp[nums[l]+nums[r]]++;
            l++;
            r++;
        }

        for(auto it:mp){
            if(it.second >= 2){
                return true;
            }
        }
        return false;
    }
};