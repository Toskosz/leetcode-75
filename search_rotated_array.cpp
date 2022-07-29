#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = nums[0];
        int m;
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;

            if (target == nums[m]){
                return m;
            } 

            if (nums[m] >= nums[l]) {
                if(target < nums[l] || target > nums[m]){
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                if (target > nums[r] || target < nums[m]){
                    r = m - 1;
                } else {
                    l = l + 1;
                }
            }
        }
        return -1;
    }
};