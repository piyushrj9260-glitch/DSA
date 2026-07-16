class Solution {
public:
    int sumofSq(int n,unordered_set<int>&st){
        if(n == 1){
            return true;
        }
        if(st.count(n)){
            return false;
        }
        st.insert(n);
        int sum = 0;
        while(n){
            sum += pow(n%10,2);
            n = n/10;
        }
        return sumofSq(sum,st);
    }

    bool isHappy(int n) {
        unordered_set<int>st;
        return sumofSq(n,st);
    }
};