class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        // cnt[g] = number of pairs whose gcd is exactly g
        vector<long long> cnt(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {

            long long c = 0;

            // Count numbers divisible by g
            for (int j = g; j <= mx; j += g)
                c += freq[j];

            cnt[g] = c * (c - 1) / 2;

            // Remove pairs already counted for multiples
            for (int j = 2 * g; j <= mx; j += g)
                cnt[g] -= cnt[j];
        }

        // Prefix array
        vector<long long> prefix(mx + 1, 0);

        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + cnt[i];

        vector<int> ans;

        for (long long q : queries) {

            int l = 1;
            int r = mx;

            while (l < r) {

                int mid = l + (r - l) / 2;

                if (prefix[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }

            ans.push_back(l);
        }

        return ans;
    }
};