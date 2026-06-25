class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m=0;
        int cnt = 0;
        for(int x : nums){
            if(x==1){
                cnt++;
                m=max(m,cnt);
            }else{
                cnt=0;
            }
        }
    return m;
        }
};