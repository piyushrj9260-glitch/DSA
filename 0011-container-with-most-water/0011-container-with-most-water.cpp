class Solution {
public:
    int maxArea(vector<int>& height) {
    int n=height.size();
    int lp=0;
    int rp=n-1;
    int ans=0;

    while(lp<rp){
        int width = rp-lp;
        int h = min(height[lp],height[rp]);
        int area = h * width;
        ans = max(ans,area);

        height[lp]<height[rp] ? lp++ : rp--;
    }
    return ans;
    }
};