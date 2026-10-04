class Solution {
public:
    void solve(vector<int>& nums,vector<bool>&used,vector<int>&curr,vector<vector<int>>&ans){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }

            used[i] = true;
            curr.push_back(nums[i]);

            solve(nums,used,curr,ans);
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>used(nums.size(),false);
        vector<int>curr;
        vector<vector<int>>ans;
        solve(nums,used,curr,ans);
        return ans;
    }
};