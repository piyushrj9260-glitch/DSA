class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int s = n*m;

        k = k%s;

        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int index = i*n+j;
                int newIndx = (index+k)%s;
                int newRow = newIndx/n;
                int newCol = newIndx%n;
                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;
    }
};