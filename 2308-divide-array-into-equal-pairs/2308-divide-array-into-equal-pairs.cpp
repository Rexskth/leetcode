class Solution {
public:
    bool divideArray(vector<int>& nums) {
        bool ans = true;
        unordered_map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        for(int i = 0; i < nums.size(); i++){
            if(mpp[nums[i]]%2 != 0){
                ans = false;
                break;
            }
        }
        // if(nums.size()==2) return true;
        return ans;
    }
};