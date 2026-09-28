class Solution {
public:
struct meeting{
    int s;
    int e;
    int pos;
};
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<meeting>m;

        for(int i=0;i<n;i++){
            m.push_back({intervals[i][0],intervals[i][1],i+1});
        }

        sort(m.begin(),m.end(),[](meeting a,meeting b){
            if(a.e == b.e){
                return a.pos < b.pos;
            }
            return a.e < b.e;
        });

        int cnt = 0;
        int lastEnd = INT_MIN;

        for(auto meet:m){
            if(meet.s >= lastEnd){
                cnt++;
                lastEnd = meet.e;
            }
        }
        return n-cnt;
    }
};