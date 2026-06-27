class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>left;
        vector<int>right;
        left.push_back(0);
        right.push_back(0);
        int leftSum = 0;
        for(int i=0;i<n-1;i++){
            leftSum += nums[i];
            left.push_back(leftSum);
        }
        int rightSum = 0;
        for(int i=n-1;i>0;i--){
            rightSum += nums[i];
            right.push_back(rightSum);
        }
        reverse(right.begin(),right.end());
        vector<int>ans;
        for(int i=0;i<n;i++){
            int diff = left[i] - right[i];
            if(diff < 0){
                diff = -diff;
            }
            ans.push_back(diff);
        }
        return ans;
    }
};