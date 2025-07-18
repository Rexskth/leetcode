class Solution {
public:
    // Divisor function with ceiling division
    int divisor(int mid, vector<int>& nums) {
        int div = 0;
        for (int i = 0; i < nums.size(); i++) {
            div += (nums[i] + mid - 1) / mid; // Ceiling division
        }
        return div;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end()); 

        while (low <= high) {
            int mid = (low + high) / 2;

            if (divisor(mid, nums) > threshold) {
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }

        return low; 
    }
};