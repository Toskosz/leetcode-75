class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix.size() - 1;
        int tmp;

        while (l<r){
            for(int i=0; i<r-l; i++){
                int top = l;
                int bot = r;

                tmp = matrix[top][l+i];
                matrix[top][l+i] = matrix[bot-i][l];
                matrix[bot-i][l] = matrix[bot][r-i];
                matrix[bot][r-i] = matrix[top+i][r];

                matrix[top+i][r] = tmp;
            }
            l++;
            r--;
        }
    }
};
