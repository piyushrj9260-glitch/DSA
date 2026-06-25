class Solution {
public:
    int numberOfChild(int n, int k) {
        int cycle = 2 * (n-1);
        int rem = k % cycle;

        if(rem <= n-1){
            return rem ;
        }
        return (n-1)-(rem - (n-1));
    }
};