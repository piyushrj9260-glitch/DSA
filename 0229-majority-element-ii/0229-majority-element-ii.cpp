class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int mini =(int)(nums.size()/3) + 1;
        vector<int>li;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == mini){
                li.push_back(nums[i]);
            }
        }
        return li;
    }
};