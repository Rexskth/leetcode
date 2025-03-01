class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {


         sort(nums.begin(),nums.end());
        vector<vector<int>> vc;
        int i,j,n=nums.size()-1;
        do{
            i=j=n;
            while(i && nums[i-1]>=nums[i]) i--;
            if(i){
                while(nums[i-1]>=nums[j]) j--;
                swap(nums[i-1],nums[j]);
            }
            reverse(nums.begin()+i,nums.end());
            vc.push_back(nums);
        }while(i);
        return vc;
        
    }
};