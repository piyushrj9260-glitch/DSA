class Solution {
public:
    int findMax(vector<int>&weights){
    int maxi = INT_MIN;
    for(int i=0;i<weights.size();i++){
        maxi = max(maxi,weights[i]);
    }
    return maxi;
    }

    int sum(vector<int>&weights){
    int s=0;
    for(int i=0;i<weights.size();i++){
        s += weights[i];
    }
    return s;
}

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int s = findMax(weights);
        int e = sum(weights);
        while(s<=e){
            int mid = s+(e-s)/2;
            int totalLoad = 0;
            int day = 1;
            for(int i=0;i<n;i++){
                if(totalLoad + weights[i] > mid){
                    day++;
                    totalLoad = weights[i];
                }else{
                    totalLoad += weights[i];
                }
            }
            if(day<=days){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return s;
    }
};