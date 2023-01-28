class Solution {
public:

    bool dfs(int index, int r, int c, vector<vector<char>>& board, string word){
        if (r<0 || c<0 || r>=board.size() || 
            c>=board[0].size() || word[index] != board[r][c]){
            return false;
        } 
        
        if (index == word.size() - 1){
            return true;
        }
        
        board[r][c] = '#';
        bool res = (dfs(index+1,r-1,c,board,word) || dfs(index+1,r+1,c, board,word) || 
            dfs(index+1,r,c-1, board,word) || dfs(index+1,r,c+1, board,word));
        board[r][c] = word[index];
        return res;
    }


    bool exist(vector<vector<char>>& board, string word) {

        for (int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if (dfs(0, i, j, board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};

