class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ans; 
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1; // Left pointer
            int k = n - 1; // Right pointer

            while (j < k) {
                int target = nums[i] + nums[j] + nums[k];

                if (target == 0) { // Valid triplet found
                    ans.push_back({nums[i], nums[j], nums[k]});

                    // Skip duplicates for j and k
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    // Move pointers
                    j++;
                    k--;
                } else if (target < 0) {
                    j++; // Increase the sum
                } else {
                    k--; // Decrease the sum
                }
            }
        }

        return ans;
    }
};


