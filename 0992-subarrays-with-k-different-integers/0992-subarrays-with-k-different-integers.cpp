class Solution {
public:
    int subarr(vector<int>&v,int k){
        if(k < 0) return 0;

        int n = v.size();
        int cnt = 0;
        int l = 0;
        int r = 0;
        unordered_map<int,int>mp;

        while(r<n){
            mp[v[r]]++;

            while(mp.size() > k){
                mp[v[l]]--;
                if(mp[v[l]] == 0){
                    mp.erase(v[l]);
                }
                l++;
            }

            if(mp.size() <= k){
                cnt += r-l+1;
            }
            r++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarr(nums,k) - subarr(nums,k-1);
    }
};