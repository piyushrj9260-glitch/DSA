class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxCnt = 0;
        int index = 0;
        for(int i=0;i<n;i++){
            int CntOnes =0;
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1){
                    CntOnes++;
                }
            }
            if(CntOnes > maxCnt){
                maxCnt = CntOnes;
                index = i;
            }
        }
        
        return {index,maxCnt};
    }
};