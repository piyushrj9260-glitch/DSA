class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int n = prices.size();
        for(int i=1;i<n;i++){
            if(prices[i] > prices[i-1]){
                int profit = prices[i] - prices[i-1];
                maxPro += profit;
            }
        }
        return maxPro;
    }
};