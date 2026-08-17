class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(),s.end());
        int start = 0;
        for(int i=0;i<=n;i++){
            if(s[i] ==' ' || i==n){
                reverse(s.begin()+start,s.begin()+i);
                start = i+1;
            }
        }
        string t="";
        int i=0;

        while(i<n){
            while(i<n && s[i]==' ') i++;

            if(i>=n) break;
            if(!t.empty()) t+=' ';

            while(i<n && s[i]!=' '){
                t += s[i];
                i++;
            }
        }

        return t;
    }
};