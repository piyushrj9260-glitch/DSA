class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for(int x:s){
            if(s.find(x-1) == s.end()){
                int cnt = 1;
                while(s.find(x+1) != s.end()){
                    cnt++;
                    x++;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};