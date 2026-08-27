class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool sign = true;

        if((dividend < 0) ^ (divisor < 0))
            sign = false;

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long ans = 0;

        while(n >= d) {

            int cnt = 0;

            while((d << (cnt + 1)) <= n)
                cnt++;

            ans += (1LL << cnt);
            n -= (d << cnt);
        }

        if(!sign)
            ans = -ans;

        return ans;
    }
};