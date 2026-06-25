class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>r;
        long long ans = 1;
        r.push_back(1);
        for(int i=1;i<=rowIndex;i++){
            ans = ans * (rowIndex+ 1-i);
            ans = ans/i;
            r.push_back(ans);
        }
        return r;
    }
};