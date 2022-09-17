class Solution {
public:
    int rows;
    int cols;
    vector<vector<bool>> visited;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    void bfs(int r, int c, vector<vector<char>>& grid){
        queue<vector<int>> queue;        
        queue.push({r, c});
        visited[r][c] = true;
        
        while(!queue.empty()){
            vector<int> actual_coord = queue.front();
            for(int i=0; i<dirs.size(); i++){
                r = actual_coord[0] + dirs[i][0];
                c = actual_coord[1] + dirs[i][1];
                if(r > 0 && r < rows && c > 0 && c < cols && grid[r][c]=='1' && !visited[r][c]){
                    queue.push({r,c});
                    visited[r][c] = true;
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid[0].size() == 0){
            return 0;
        }
        
        rows = grid.size();
        cols = grid[0].size();
        int islands = 0;
        
        for(int r=0; r<rows; r++){
            vector<bool> x(cols, false);
            visited.push_back(x);
        }
        
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if (grid[r][c]=='1' && !visited[r][c]){
                    bfs(r,c,grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};
