class Solution {
public:
    int oddsum(int n){
        int sum = 0;
        int c = 1;
        for(int i=1;i<=n;i++){
            sum += c;
            c = c+2;
        }
        return sum;
    }

    int evensum(int n){
        int sum = 0;
        int c = 2;
        for(int i=1;i<=n;i++){
            sum += c;
            c = c+2;
        }
        return sum;
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd = oddsum(n);
        int sumEven = evensum(n);
        int m = min(sumOdd,sumEven);
        for(int i = m;i>=2;i--){
            if(sumOdd%i==0 && sumEven%i == 0){
                return i;
            }else{
                continue;
            }
        }
        return 1;
        
    }
};