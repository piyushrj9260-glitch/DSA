class Solution {
public:
    int findmax(vector<int>&v){
        int maxi = INT_MIN;
        for(int i=0;i<v.size();i++){
            maxi = max(maxi,v[i]);
        }
        return maxi;
    }

    long long calculateTotalHour(vector<int>&v,int hourly){
        int n = v.size();
        long long totalH = 0;
        for(int i=0;i<n;i++){
            totalH += ceil((double)v[i] / (double)hourly);
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& v, int h) {
        int s = 1;
        int e = findmax(v);
        while(s<=e){
            int mid = s+(e-s)/2;
            long long totalH = calculateTotalHour(v,mid);
            if(totalH<=h){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return s;
    }
};