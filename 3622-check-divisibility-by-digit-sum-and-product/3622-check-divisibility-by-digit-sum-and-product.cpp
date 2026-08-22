class Solution {
public:
    bool checkDivisibility(int n) {

        long long sum = 0;
        long long prod = 1;

        int t = n;

        while(t != 0){
            int digit = t % 10;

            sum += digit;
            prod *= digit;

            t /= 10;
        }

        return n % (sum + prod) == 0;
    }
};