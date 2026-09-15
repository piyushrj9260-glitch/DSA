class Solution {
public:
    vector<int>pse(vector<int>& heights,int n){
        vector<int>left(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
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

    vector<int>nse(vector<int>& heights,int n){
        vector<int>right(n);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
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

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left = pse(heights,n);
        vector<int>right = nse(heights,n);

        int ans = 0;
        for(int i=0;i<n;i++){
            int width = right[i] - left[i] -1;
            int area = width * heights[i];
            ans = max(ans,area);
        }
        return ans;
    }
};