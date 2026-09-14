class Solution {
public:
    long long sumOfSubArrayMin(vector<int>&nums,int n){

        vector<int>left(n);
        vector<int>right(n);

        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = i+1;
            }else{
                left[i] = i - st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty()){
                right[i] = n-i;
            }else{
                right[i] = st.top() - i;
            }
            st.push(i);
        }

        long long ans = 0;
        for(int i=0;i<n;i++){
            ans = (ans+1LL*nums[i]*left[i]*right[i]);
        }
        return ans;
    }

    long long sumOfSubArrayMax(vector<int>&nums,int n){

        vector<int>left(n);
        vector<int>right(n);

        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = i+1;
            }else{
                left[i] = i - st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                right[i] = n-i;
            }else{
                right[i] = st.top()-i;
            }
            st.push(i);
        }

        long long ans = 0;
        for(int i=0;i<n;i++){
            ans = (ans + 1LL * nums[i] * left[i] * right[i]);
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        long long sumOfSubArrMini = sumOfSubArrayMin(nums,n);

        long long sumOfSubArrMaxi = sumOfSubArrayMax(nums,n);

        return (sumOfSubArrMaxi - sumOfSubArrMini);
    }
};