class Solution {
    private: 
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        int n = grid.size();
        int m = grid[0].size();

        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] ==0 || visited[i][j]==true){
            return 0;
        }

        int gold = grid[i][j];
        visited[i][j] = true;
        // grid[i][j] = 0;

        int maxgold = max({dfs(i,j-1,grid, visited), dfs(i-1,j,grid, visited),
                            dfs(i+1,j,grid, visited), dfs(i,j+1,grid, visited)});

            // grid[i][j] = gold;
            visited[i][j] = false;
            return gold + maxgold;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxG = 0;
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    maxG = max(maxG, dfs(i,j,grid,visited));
                }
            }
        }
        return maxG;
    }
};