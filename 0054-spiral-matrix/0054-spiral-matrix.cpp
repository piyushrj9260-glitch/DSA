class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        vector<int>ans;
    int n = v.size();
    int m = v[0].size();
    int left = 0;
    int right = m-1;
    int top = 0;
    int bottom = n-1;

    while(left<=right && top<=bottom){
        //left to right
        for(int i=left;i<=right;i++){
            ans.push_back(v[top][i]);
        }
        top++;
        //top to bottom
        for(int i=top;i<=bottom;i++){
            ans.push_back(v[i][right]);
        }
        right--;
        //bottom right to left
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(v[bottom][i]);
            }
            bottom--;
        }
        //bottom to top
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(v[i][left]);
            }
            left++;
        }
    }
    return ans;
    }
};