class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int cache_matrix[text1.length()+1][text2.length()+1];

        for (auto &row: cache_matrix){
            for (auto &e: row) {
                e = 0;
            }
        }

        for(int i=text1.length()-1; i>-1; i--){
            for(int j=text2.length()-1; j>-1; j--){
                if(text1[i] == text2[j]){
                    cache_matrix[i][j] = 1 + cache_matrix[i+1][j+1];
                } else {
                    cache_matrix[i][j] = max(cache_matrix[i][j+1], cache_matrix[i+1][j]);
                }
            }
        }
        return cache_matrix[0][0];
    }
};
