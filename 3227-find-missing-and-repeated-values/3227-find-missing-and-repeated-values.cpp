class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
       

      long long n = grid.size()*grid.size();
        long long sum1 = n*(n+1)/2;
        long long sum2 = n*(n+1)*(2*n+1)/6;

        long long sum11 = 0;
        long long sum22 = 0;

          for(int i = 0; i < grid.size();i++){
            for(int j = 0; j <grid.size();j++){
                sum11 += grid[i][j];
                sum22 += grid[i][j]*grid[i][j];
            }
          }

         long long x = sum1 - sum11;
         long long y = (sum2-sum22)/x;

         long long b = (y-x)/2;
         long long a = (x+y)/2; 



             ans.push_back(b);
             ans.push_back(a);
        return ans;
    }
};