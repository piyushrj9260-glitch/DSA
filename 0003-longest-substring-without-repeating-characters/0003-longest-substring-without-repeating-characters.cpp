class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        int l = 0;
        int r = 0;
        unordered_map<char, int> mp;

        while (r < n) {
            if (mp.find(s[r]) == mp.end()) {
                mp[s[r]] = r;
            } else{
                if (mp[s[r]] >= l) {
                    l = mp[s[r]] + 1;
                }
                mp[s[r]] = r;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};