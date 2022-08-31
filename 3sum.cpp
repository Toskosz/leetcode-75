class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l,r,tmpSum;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 and nums[i] == nums[i-1]){
                continue;
            }

            l = i + 1;
            r = nums.size() - 1;
            while (l < r){
                tmpSum = nums[i] + nums[r] + nums[l];
                if (tmpSum > 0){
                    r--;
                } else if (tmpSum < 0){
                    l++;
                } else {
                    res.push_back(vector<int> { nums[i], nums[l], nums[r]});
                    l++;
                    while ((nums[l] == nums[l-1]) && l < r){
                        l++;
                    }
                }
            }
        }
        return res;
    }
};
