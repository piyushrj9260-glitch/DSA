class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        vector<int>ans;
        for(auto it:mp){
            if(it.second == 2){
                ans.push_back(it.first);
            }
        }

        for(int i=1;i<=n;i++){
            if(mp.find(i) == mp.end()){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};