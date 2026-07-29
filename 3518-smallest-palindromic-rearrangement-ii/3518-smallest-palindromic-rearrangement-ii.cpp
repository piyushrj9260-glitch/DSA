class Solution {
public:
    const long long LIMIT = 1000001;

    long long nCr(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);

        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - i + 1) / i;
            if (ans > LIMIT) return LIMIT;
        }

        return ans;
    }

    long long countWays(vector<int>& cnt) {

        int total = 0;

        for (int x : cnt)
            total += x;

        long long ans = 1;

        for (int x : cnt) {

            ans *= nCr(total, x);

            if (ans > LIMIT)
                return LIMIT;

            total -= x;
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        string mid = "";

        vector<int> half(26);

        int len = 0;

        for (int i = 0; i < 26; i++) {

            half[i] = cnt[i] / 2;

            len += half[i];

            if (cnt[i] % 2)
                mid = char('a' + i);
        }

        if (countWays(half) < k)
            return "";

        string left = "";

        while (len--) {

            for (int i = 0; i < 26; i++) {

                if (half[i] == 0)
                    continue;

                half[i]--;

                long long ways = countWays(half);

                if (ways >= k) {

                    left.push_back(char('a' + i));
                    break;

                } else {

                    k -= ways;
                    half[i]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};