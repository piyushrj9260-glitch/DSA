class Solution {
public:

    int findMin(vector<int>&bloomDay){
        int mini = INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            mini = min(mini,bloomDay[i]);
        }
        return mini;
    }

    int findMax(vector<int>&bloomDay){
        int maxi = INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            maxi = max(maxi,bloomDay[i]);
        }
        return maxi;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n =bloomDay.size();
        if((long long)m*k>n){
            return -1;
        }
        int s = findMin(bloomDay);
        int e = findMax(bloomDay);
        int ans = 0;
        while(s<=e){
            int mid = s+(e-s)/2;
            int totalBou = 0;
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    cnt++;
                }else{
                    totalBou += cnt/k;
                    cnt=0;
                }
            }
            totalBou += cnt/k;
            if(totalBou >= m){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};