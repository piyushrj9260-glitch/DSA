class Solution {
public:
    bool rotateString(string s, string goal) {
        
        for(int i=0;i<s.size();i++){
            string temp = s;

            reverse(temp.begin(),temp.end());
            reverse(temp.begin(),temp.begin()+i);
            reverse(temp.begin()+i,temp.end());
            if(temp == goal){
                return true;
            }
            
        }
        return false;
    }
};