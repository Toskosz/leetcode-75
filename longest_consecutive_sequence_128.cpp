class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numsSet(nums.begin(), nums.end());
        int result = 0;
        set<int>::reverse_iterator itr;
        
        for (itr = numsSet.rbegin();itr != numsSet.rend(); itr++){
            if (numsSet.find(*itr-1) == numsSet.end()){
                int len = 1;
                while(numsSet.find(*itr+len) != numsSet.end()){
                    len++;
                }
                result = max(len, result);
            }
        }
        return result;
    }
};
