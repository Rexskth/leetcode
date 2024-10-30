class Solution {
public:
    int jump(vector<int>& nums) {

         int n=nums.size();
        int ld=0,ans=0,md=0;
        for(int i=0;i<n;i++){
            
            if(i>ld){
                ans++;
                ld=md;
            }
            md=max(md,i+nums[i]);
        }
        return ans;
        
    }
};