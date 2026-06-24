class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0){
            return false;
        }
        unsigned int y = 0;
        int temp = x;
        while(x != 0){
            y = y*10 + x % 10;
            x = x/10;
        }
         
        if(temp == y){
            return true;
        } 
        return false;
    }
};