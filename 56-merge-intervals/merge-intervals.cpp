class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& Intervals) {


      sort(Intervals.begin(), Intervals.end());
        vector<vector<int>> ans;
        int  n = Intervals.size();

        for(int i = 0; i < n; i++){

            if( !ans.empty() && Intervals[i][0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1], Intervals[i][1]);
            }else{
                ans.push_back(Intervals[i]);
            }
        }
        return ans;
    }
};