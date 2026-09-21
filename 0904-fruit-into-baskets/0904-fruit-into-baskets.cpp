class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxFruit = 0;
        unordered_map<int,int>mp;
        int l = 0;
        int r = 0;

        while(r<n){
            mp[fruits[r]]++;
            if(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size() <= 2){
                maxFruit = max(maxFruit,r-l+1);
            }
            r++;
        }
        return maxFruit;
    }
};