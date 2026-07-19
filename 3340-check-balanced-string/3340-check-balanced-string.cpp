class Solution {
public:
    

    bool isBalanced(string num) {
        int sumEven = 0;
        int sumOdd = 0;
        for(int i=0;i<num.size();i++){
            if(i%2 != 0){
                sumOdd += (int)('0'-num[i]);
            }else{
                sumEven += (int)('0'-num[i]);
            }
        }
        if(sumOdd != sumEven){
            return false;
        }
        return true;
    }
};