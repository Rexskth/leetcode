class Solution {
public:

    int findIndex(int n , vector<int> &nums , vector<int> &ans , int target ,bool findFirst )
    {
        int val = -1;
        int start = 0;
        int end =  n - 1;

        while(start <= end)
        {
            int mid = start + ( end - start) / 2;

            if(nums[mid] > target)
            {
                end = mid - 1;
            }

           else if(nums[mid] < target)
            {
               start = mid + 1;
            }

            else 
         {
            val = mid;

            if(findFirst)
                {
                    end = mid - 1;
                }
                else 
                {
                    start = mid + 1;
                }

         }


        }

        return val;

    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> ans = { -1 , - 1};

      ans[0] =   findIndex(n , nums , ans , target , true);
      ans[1] =   findIndex(n , nums , ans , target , false);


        return ans;

    }
};