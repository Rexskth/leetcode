class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0, MaxSum = 0;

        unordered_set<int> st;

        while (r < n) {
            while (st.count(nums[r])) { 
                st.erase(nums[l]);
                sum -= nums[l];
                l++;
            }

            st.insert(nums[r]);
            sum += nums[r];
            MaxSum = max(sum, MaxSum);
            r++;
        }

        return MaxSum;
    }
};