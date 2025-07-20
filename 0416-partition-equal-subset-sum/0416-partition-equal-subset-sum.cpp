class Solution {
public:
bool sumFind(int ind, int target,vector<int>& nums, vector<vector<int>>& dp){
    if(target==0) return true;
    if(ind==0) return nums[0] == target;
    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = sumFind(ind-1,target,nums,dp);
    bool Taken= false;

    if(nums[ind]<=target){
        Taken = sumFind(ind-1,target-nums[ind],nums,dp);
    }
    return dp[ind][target]= Taken || notTaken;
}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
       
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
         vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));
         if(sum%2!=0) return false;
     else  return sumFind(n-1,sum/2,nums,dp);
    }
};