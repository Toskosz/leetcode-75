class Solution {
public:
    bool canJump(vector<int>& nums) {
        int soFar = nums.size() - 1;

        for(int i=nums.size()-1; i>-1; i--){
            if(i+nums[i]>=soFar){
                soFar = i;
            }
        }

        if(soFar==0){
            return true;
        }else {
            return false;
        }
    }
};
