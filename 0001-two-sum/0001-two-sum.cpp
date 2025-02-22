class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // sort(nums.begin(), nums.end());
        vector<int> ans;
        unordered_map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++){

            if(mpp.find(target - nums[i]) != mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[target-nums[i]]);
                // return ans;
            }


            mpp[nums[i]] = i;
        }




        return ans;
        
    }
};