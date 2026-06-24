class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        
        int i=0;
        for(auto it:s){
            nums[i]=it;
            i++;
        }
        
        return s.size();
    }
};