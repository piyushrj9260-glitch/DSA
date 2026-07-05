class Solution {
public:
    bool isPerfectSquare(int num) {
        bool ans = false;
        long long s = 0;
        long long e = num;
        while(s<=e){
            long long mid = s+(e-s)/2;
            if((mid * mid) == num){
                ans = true;
                break;
            }else if(mid*mid < num){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
    }
};