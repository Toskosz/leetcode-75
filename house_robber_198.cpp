class Solution {
public:
    int rob(vector<int>& nums) {
        int casa_a = 0;
        int casa_b = 0;
        int tmp;

        for(int i=0; i<nums.size(); i++){
            tmp = max(casa_a + nums[i], casa_b);
            casa_a = casa_b;
            casa_b = tmp;
        }

        return casa_b;
    }
};
