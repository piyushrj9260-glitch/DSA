class Solution {
public:
    void solve(vector<int>&candidates, int target,int indx,vector<int>&current,
        vector<vector<int>>&ans){
            if(target == 0){
                ans.push_back(current);
                return;
            }

            if(target<0 || indx == candidates.size()){
                return;
            }

            current.push_back(candidates[indx]);

            solve(candidates,target - candidates[indx],indx,current,ans);

            current.pop_back();

            solve(candidates,target,indx+1,current,ans);
        }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>current;
        vector<vector<int>>ans;

        solve(candidates,target,0,current,ans);
        return ans;
    }
};