class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mini = nums[0];
        int max = nums[n-1];
        vector<int>ans;
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=mini;i<=max;i++){
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};