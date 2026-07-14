class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max = LLONG_MIN;
        long long sMax = LLONG_MIN;
        long long tMax = LLONG_MIN;

        for(int x : nums){
            if(x == max || x == sMax || x == tMax){
                continue;
            }
            if(x>max){
                tMax = sMax;
                sMax = max;
                max = x;
            }else if(x>sMax){
                tMax = sMax;
                sMax = x;
            }else if(x>tMax){
                tMax = x;
            }
        }
        return (tMax == LLONG_MIN)? max:tMax;
    }
};