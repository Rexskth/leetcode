class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int ans = 0;
        int zero_count = 0;

        while(right<nums.size()){
            if(nums[right]==0) zero_count++;

            while(zero_count>k){
                if(nums[left]==0) zero_count--;
                left++;
            }

            ans = max(ans, right-left+1);
            right++;
        }

        return ans;
        
    }
};