class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        int maxF = 0;
        int hash[26] = {0};

        while(r<n){
            hash[s[r]-'A']++;
            maxF = max(maxF,hash[s[r]-'A']);

            int changes = (r-l+1) - maxF;
            if(changes > k){
                hash[s[l]-'A']--;
                l++;
            }

            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};