class Solution {
public:
        long long gcdSum(vector<int>& nums) {
        int maxi = INT_MIN;
        vector<int>prefixGcd;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            prefixGcd.push_back(__gcd(maxi,nums[i]));
            
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long sum = 0;
        long long left = 0;
        long long right = prefixGcd.size()-1;
        while(left<right){
            sum += __gcd(prefixGcd[left],prefixGcd[right]);
            left++;
            right--;
        }
        return sum;
    }
};