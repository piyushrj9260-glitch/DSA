class Solution {
public:
    vector<int> countBits(int n) {
       vector<int>ans;
       
       for(int i=0;i<=n;i++){
       int m = i; 
       int cnt = 0;
            while(m>0){
               cnt += (m & 1);
               m = m>>1;
            }
            ans.push_back(cnt);
       } 
       return ans;
    }
};