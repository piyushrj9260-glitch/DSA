class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int read = 0;
        int write = 0;

        while(read<n){
            char curr = chars[read];
            int count = 0;
            while(read<n && curr == chars[read]){
                count++;
                read++;
            }
            chars[write++] = curr;

            if(count>1){
            string cnt = to_string(count);
            for(char c:cnt){
                chars[write++] = c;
                }
            }
        }
        return write;
    }
};