class Solution {
    private: 
     void fun(int ind, vector < int > & nums, vector < int > & ds, vector < vector < int >> & ans) {
         ans.push_back(ds);

         for (int i = ind; i < nums.size(); i++) {   // making sure each and every element should be visited
            if (i != ind && nums[i] == nums[i - 1]) continue;  // to avoid duplicates
            ds.push_back(nums[i]);    //case of element picked
            fun(i + 1, nums, ds, ans);
            ds.pop_back();   // this is when element is not picked
         }
      }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
           vector < vector < int >> ans;
    sort(nums.begin(), nums.end());  // doinng this for duplicates, it helps to takle with duplicates
    vector < int > ds;
    fun(0, nums, ds, ans);
   
    return ans;
    }
};