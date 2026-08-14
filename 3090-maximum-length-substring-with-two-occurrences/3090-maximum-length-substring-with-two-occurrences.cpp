class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char ,int>mpp;
        int n= s.size();
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            while( mpp[s[i]]>2){
                mpp[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;

        
    }
};