class Solution {
public:
    bool canWePlace(vector<int>&position,int dis,int m){
        int n = position.size();
        int CNTm = 1;
        long long lastDis = position[0];
        for(int i=1;i<n;i++){
            if(position[i]-lastDis>=dis){
                CNTm++;
                lastDis = position[i];
            }
            if(CNTm >= m){
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        long long s = 1;
        long long e = position[n-1]-position[0];
        while(s<=e){
            long long mid = s+(e-s)/2;
            if(canWePlace(position,mid,m)==true){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return e;
    }
};