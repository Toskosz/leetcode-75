class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
        vector<int> cache(amount+1, amount+1);
        cache[0] = 0;

        for(int i=1; i<amount+1; i++){
            for(int j=0; j<coins.size(); j++){
                if(i-coins[j] >= 0){
                    cache[i] = min(cache[i], 1 + cache[i - coins[j]]);
                }
            }
        }

        if (cache[amount] != amount + 1){
            return cache[amount];
        }
        return -1;
    }
};
