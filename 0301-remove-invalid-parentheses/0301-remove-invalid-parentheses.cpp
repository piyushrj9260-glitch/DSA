class Solution {
public:

    unordered_set<string> ans;

    void solve(string& s,
               int index,
               int leftCount,
               int rightCount,
               int leftRemove,
               int rightRemove,
               string& current) {

        // Invalid prefix
        if(rightCount > leftCount)
            return;

        // End of string
        if(index == s.size()) {

            if(leftRemove == 0 && rightRemove == 0) {
                ans.insert(current);
            }

            return;
        }

        char c = s[index];

        // -------------------------
        // Case 1: Remove character
        // -------------------------

        if(c == '(' && leftRemove > 0) {

            solve(s,
                  index + 1,
                  leftCount,
                  rightCount,
                  leftRemove - 1,
                  rightRemove,
                  current);
        }

        if(c == ')' && rightRemove > 0) {

            solve(s,
                  index + 1,
                  leftCount,
                  rightCount,
                  leftRemove,
                  rightRemove - 1,
                  current);
        }


        // -------------------------
        // Case 2: Keep character
        // -------------------------

        current.push_back(c);

        if(c == '(') {

            solve(s,
                  index + 1,
                  leftCount + 1,
                  rightCount,
                  leftRemove,
                  rightRemove,
                  current);
        }

        else if(c == ')') {

            solve(s,
                  index + 1,
                  leftCount,
                  rightCount + 1,
                  leftRemove,
                  rightRemove,
                  current);
        }

        else {

            // Letter
            solve(s,
                  index + 1,
                  leftCount,
                  rightCount,
                  leftRemove,
                  rightRemove,
                  current);
        }

        current.pop_back();
    }


    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum removals
        for(char c : s) {

            if(c == '(') {
                leftRemove++;
            }

            else if(c == ')') {

                if(leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        string current;

        solve(s,
              0,
              0,
              0,
              leftRemove,
              rightRemove,
              current);

        return vector<string>(ans.begin(), ans.end());
    }
};