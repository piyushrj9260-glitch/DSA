class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle = 2*(n-1);
        int rem = time % cycle;
        //pillow is moving in forward direction
        if(rem <= n-1){
            return rem + 1;
        }
        //in backward direction
        return n - (rem - (n-1));

    }
};