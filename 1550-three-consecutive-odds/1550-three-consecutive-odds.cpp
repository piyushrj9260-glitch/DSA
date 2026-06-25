class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        int maxCnt = INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2 != 0){
                count++;
                maxCnt = max(maxCnt,count);

            }else{
                count = 0;
            }
        }
        if(maxCnt >= 3){
            return true;
        }
        return false;
    }
};