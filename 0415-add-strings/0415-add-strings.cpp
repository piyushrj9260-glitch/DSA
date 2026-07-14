class Solution {
public:
    string addStrings(string nums1, string nums2) {
        int i = nums1.size()-1;
        int j = nums2.size()-1;
        int carry = 0;
        string ans = "";
        while(i>=0 || j>=0 || carry){
            int sum = carry;
            if(i>=0){
                sum += nums1[i--]-'0';
            }
            if(j>=0){
                sum += nums2[j--]-'0';
            }
            ans.push_back((sum%10)+'0');
            carry = sum/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};