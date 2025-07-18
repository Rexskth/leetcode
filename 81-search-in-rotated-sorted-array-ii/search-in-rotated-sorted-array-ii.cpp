class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (nums[mid] == target)
                return true;

            // agar left half is sorted
            if (nums[l] < nums[mid]) {
                if (nums[l] <= target && target < nums[mid])
                    h = mid - 1;  
                else
                    l = mid + 1;   
            }
            // agar left half is not sorted, then right half must be sorted
            else if (nums[l] > nums[mid]){
                if (nums[mid] < target && target <= nums[h])
                    l = mid + 1;   
                else
                    h = mid - 1;   
            }
            
            else {
                l++;
            }
        }

        return false;
    }
};