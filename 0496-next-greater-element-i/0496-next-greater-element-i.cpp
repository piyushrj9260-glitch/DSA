class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mpp;
        int n = nums2.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                mpp[nums2[i]] = -1;
            }
            if(!st.empty()){
                mpp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int x:nums1){
            ans.push_back(mpp[x]);
        }
        return ans;
    }
};