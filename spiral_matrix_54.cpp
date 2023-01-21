class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom = matrix.size();
        int left = 0;
        int right = matrix[0].size();

        vector<int> result;

        while (top<bottom && left<right){
            // top i
            for (int i=left; i<right; i++){
                result.push_back(matrix[top][i]);
            }
            top++;
            // right i
            for (int i=top; i<bottom; i++){
                result.push_back(matrix[i][right-1]);
            }
            right--;

            if (!(top<bottom && left<right)){
                break;
            }

            // bottom i
            for (int i=right-1;i>left-1; i--){
                result.push_back(matrix[bottom-1][i]);
            }
            bottom--;
            // left i
            for (int i=bottom-1; i>top-1; i--){
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        return result;
    }
};
