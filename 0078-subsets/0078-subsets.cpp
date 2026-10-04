class Solution {
public:
    void subset(vector<int>& nums,int indx,vector<int>&curr,vector<vector<int>>&ans){
        if(indx == nums.size()){
            ans.push_back(curr);
            return;
        }
        subset(nums,indx+1,curr,ans);
        curr.push_back(nums[indx]);
        subset(nums,indx+1,curr,ans);
        curr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        subset(nums,0,curr,ans);
        return ans;
    }
};