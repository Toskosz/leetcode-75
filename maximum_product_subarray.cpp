#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // In case of vector with len == 1
        int res = *max_element(nums.begin(), nums.end());

        int cur_min = 1;
        int cur_max = 1;

        for (auto & element : nums) {
            if(element == 0){
                // 1 is the neutral element, otherwise all subarray's could end up == 0
                cur_min = 1;
                cur_max = 1;
                continue;
            } else {
                int temp_cur_max = cur_max * element;
                
                int tmp_comp = max(element * cur_max, element * cur_min);
                cur_max = max(tmp_comp, element);

                tmp_comp = min(temp_cur_max, element * cur_min);
                cur_min = min(tmp_comp, element);

                res = max(res, cur_max);
            }
        }
        return res;
    }
};