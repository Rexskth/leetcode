class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int r = 0, l = 0, zeroCount = 0;
        int length = 0;

        while(r<nums.size()){
            if(nums[r] == 0) zeroCount++;

            while(zeroCount>k){
                if(nums[l] == 0){
                zeroCount--;
                }
                l++;
            }

            length = max(length, r-l+1);
            r++;

        }
        return length;
        
    }
};