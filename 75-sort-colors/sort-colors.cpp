class Solution {
public:
    void sortColors(vector<int>& nums) {
        

        int n = nums.size();

        int l=0,h=n-1,mid=0;

        while(mid<=h){
            if(nums[mid]==0){
                swap(nums[mid],nums[l]);
                l++;
                mid++;

            }else if(nums[mid]==2){
                swap(nums[mid],nums[h]);
                    h--;
                }else{
                    mid++;
                }
            }
        }
    
};