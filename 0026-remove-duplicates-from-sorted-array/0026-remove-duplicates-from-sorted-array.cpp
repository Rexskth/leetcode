class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> ans;
        int n = nums.size();
        int k = 1; // Start with 1 since the first element is always counted

        ans.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1]) { // Compare with the previous element
                ans.push_back(nums[i]);
                k++;
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            nums[i] = ans[i];
        }

        return k;
    }
};
