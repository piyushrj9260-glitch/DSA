class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int n = word1.size();
        int m = word2.size();
        int left = 0;
        int right = 0;
        
        while(left<n && right<m){
            s.push_back(word1[left++]);
            
            s.push_back(word2[right++]);
            
        }
        while(left<n){
            s.push_back(word1[left++]);
        }
        while(right<m){
            s.push_back(word2[right++]);
        }
        return s;
    }
};