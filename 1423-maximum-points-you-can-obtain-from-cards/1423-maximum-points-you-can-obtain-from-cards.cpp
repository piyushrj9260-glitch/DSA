class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0;
        int rsum = 0;
        int maxPnt = INT_MIN;

        for(int i=0;i<k;i++){
            lsum += cardPoints[i];
        }
        maxPnt = max(maxPnt,lsum);

        int rightIndx = n-1;
        for(int i=k-1;i>=0;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rightIndx];
            rightIndx--;

            maxPnt = max(maxPnt,lsum+rsum);
        }
        return maxPnt;
    }
};