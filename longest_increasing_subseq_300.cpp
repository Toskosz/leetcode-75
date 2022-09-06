class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cache(nums.size(), 1);

        for(int i=nums.size()-1; i>-1; i--){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] < nums[j]){
                    cache[i] = max(cache[i], 1+cache[j]);
                }
            }
        }
        return *max_element(cache.begin(), cache.end());
    }
};
