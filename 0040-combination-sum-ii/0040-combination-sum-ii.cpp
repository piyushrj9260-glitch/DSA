class Solution {
public:
    void solve(vector<int>& candidates,int indx,int target,vector<int>&current,
        vector<vector<int>>&ans){
            if(target == 0){
                ans.push_back(current);
                return;
            }

            for(int i=indx;i<candidates.size();i++){
                if(i>indx && candidates[i]==candidates[i-1]){
                    continue;
                }

                if(candidates[i] > target){
                    break;
                }

                current.push_back(candidates[i]);

                solve(candidates,i+1,target-candidates[i],current,ans);

                current.pop_back();
            }
        }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>current;
        vector<vector<int>>ans;
        solve(candidates,0,target,current,ans);
        return ans;
    }
};