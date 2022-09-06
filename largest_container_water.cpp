class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int area = 0;
        int l = 0;
        int r = height.size() - 1;

        while(l<r){
            if (height[l] < height[r]){
                area = (r-l) * height[l];
                l++;
            } else {
                area = (r-l) * height[r];
                r--;
            }

            if (area > res){
                res = area;
            }
        }
        return res;
    }
};
