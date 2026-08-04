class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mini = nums[0];
        int max = nums[n-1];
        vector<int>ans;
        set<int>st(nums.begin(),nums.end());
        for(int i=mini+1;i<=max-1;i++){
            if(st.count(i) == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};