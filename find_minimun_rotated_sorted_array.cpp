#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int res  = nums[0];
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            // vector is sorted.
            if (nums[l] < nums[r]) {
                // [4,5,1,2,3]
                res = min(res, nums[l]);
                return res;
            } else {
                int m = (l + r) / 2;
                res = min(res, nums[m]);

                // If greater than the left all numbers after the left are also greater 
                // and because the vector is rotated the left cant be the min so we search on the right
                // same logic applies for the else part.
                if (nums[m] >= nums[l]){
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return res;
    }
};