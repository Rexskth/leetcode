class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
      unordered_set<int> stt;
      unordered_set<int> st;

      for(int i = 0; i<nums.size();i++){
        if(st.count(nums[i]+k)){
          stt.insert(nums[i]);
        }

         if(st.count(nums[i]-k)){
          stt.insert(nums[i]-k);
        }
        

        st.insert(nums[i]);
      }
         return stt.size();
    }
};