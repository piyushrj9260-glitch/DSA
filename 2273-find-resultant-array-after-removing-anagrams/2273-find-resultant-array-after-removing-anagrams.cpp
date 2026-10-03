class Solution {
public:
    bool check(string s1,string s2){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());

        return (s1 == s2);
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string>ans;
        ans.push_back(words[0]);
        for(int i=1;i<n;i++){
            if(!check(ans.back(),words[i])){
                ans.push_back(words[i]);
            }
        }        
        return ans;
    }
};