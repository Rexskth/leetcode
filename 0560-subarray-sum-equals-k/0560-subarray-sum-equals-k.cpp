class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> Map;
        Map[0]=1;

        int presum = 0;
        int cnt = 0;


        for(int num : nums){
            presum += num;

            if(Map.find(presum-k) != Map.end()){
                cnt += Map[presum-k];
            }

            Map[presum]++;

        }
        return cnt;
    }
};