class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int k = n*m;
        vector<int>hash(k+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                hash[grid[i][j]]++;
            }
        }
        int repeating = -1;
        int missing = -1;
       
        for(int i=1;i<=k;i++){
            if(hash[i] == 2){
                repeating = i;
            }
            else if(hash[i] == 0){
                missing = i;
            }
            if(repeating != -1 && missing != -1){
                break;
            }
        }
        return {repeating,missing};
    }
};