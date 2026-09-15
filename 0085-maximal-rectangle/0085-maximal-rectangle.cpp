class Solution {
public:
    vector<int>pse(vector<int>&v,int n){
        vector<int>left(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && v[st.top()] >= v[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = -1;
            }else{
                left[i] = st.top();
            }
            st.push(i);
        }
        return left;
    }

    vector<int>nse(vector<int>&v,int n){
        vector<int>right(n);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && v[st.top()] >= v[i]){
                st.pop();
            }
            if(st.empty()){
                right[i] = n;
            }else{
                right[i] = st.top();
            }
            st.push(i);
        }
        return right;
    }

    int largestRecangleArea(vector<int>&v){
        int n = v.size();

        vector<int>left = pse(v,n);
        vector<int>right = nse(v,n);

        int ans = 0;
        for(int i=0;i<n;i++){
            int width = right[i] - left[i] -1;
            int area = v[i] * width;
            ans = max(ans,area);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea = 0;

        vector<vector<int>>preSum(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            int sum = 0;
            for(int i=0;i<n;i++){
                if(matrix[i][j] == '0'){
                    sum = 0;
                }else{
                    sum ++;
                }
                preSum[i][j] = sum;
            }
        }

        for(int i=0;i<n;i++){
            int area = largestRecangleArea(preSum[i]);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};