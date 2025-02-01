class Solution {
private:
    void bfs(int startRow, int startCol, vector<vector<int>>& visited, vector<vector<char>>& grid) {
        
        visited[startRow][startCol] = 1;
        queue<pair<int, int>> q;
        q.push({startRow, startCol});
        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
            int currentRow = q.front().first;
            int currentCol = q.front().second;
            q.pop();

            for (int delrow = -1; delrow <= 1; delrow++) {
               
                    int nrow = currentRow + delrow;
                    
                    if (nrow >= 0 && nrow < n && currentCol >= 0 && currentCol < m && grid[nrow][currentCol] == '1' && !visited[nrow][currentCol]) {
                        visited[nrow][currentCol] = 1;
                        q.push({nrow, currentCol});
                    }
                
            }
            
                for (int delcol = -1; delcol <= 1; delcol++) {
                   
                    int ncol = currentCol + delcol;
                    if (currentRow >= 0 && currentRow < n && ncol >= 0 && ncol < m && grid[currentRow][ncol] == '1' && !visited[currentRow][ncol]) {
                        visited[currentRow][ncol] = 1;
                        q.push({currentRow, ncol});
                    }
                }
            
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        // if (n == 0) return 0;  // Handle the case where the grid is empty
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int row = 0; row < n; row++) {
            for (int col = 0;col< m; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, visited, grid);
                }
            }
        }

        return cnt;
    }
};
