class Solution {
public:
    int digitProduct(int n){
        int pro = 1;
        while(n != 0){
            pro = pro * (n%10);
            n = n/10; 
        }
        return pro;
    }

    int smallestNumber(int n, int t) {
       while(true){
        if(digitProduct(n)%t == 0){
            return n;
        }
            n++;
       } 
    }
};