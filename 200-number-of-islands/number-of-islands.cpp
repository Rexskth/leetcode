class Solution {
    private: 

    void dfs(int i, int j, vector<vector<char>>& grid){
       int row = grid.size();
       int col = grid[0].size();

       if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == '0'){
        return;
       }

       grid[i][j] = '0';

       dfs(i, j + 1, grid);  // right
       dfs(i + 1, j, grid);  // down
       dfs(i - 1, j, grid);  // up
       dfs(i, j - 1, grid); // left

    }


public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

      if(n == 0) return 0;
      int cnt = 0;


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, grid);
                }
            }

        }
        return cnt;
        
    }
};