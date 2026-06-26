class Solution {
public:
    int alternateDigitSum(int n) {
        stack<int>st;
        while(n!=0){
            st.push(n%10);
            n = n/10;
        }
        int sum = 0;
        int c=1;
        while(!st.empty()){
            if(c%2 != 0){
                sum=sum+st.top();
                st.pop();
                c++;
            }else{
                sum = sum - st.top();
                st.pop();
                c++;
            }
        }
        return sum;
    }
};