class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        vector<int>ans;
        int n = v.size();

        deque<int>dq;

        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            while(!dq.empty() && v[dq.back()] <= v[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i>=k-1){
                ans.push_back(v[dq.front()]);
            }
        }
        return ans;

    }
};