#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        int sum = 0;
        int ans = 0;

        // Initialize with prefix sum zero to handle cases where sum directly equals `k`
        prefixSumCount[0] = 1;

        for (int num : nums) {
            sum += num;

            // Check if there exists a prefix sum that, when removed, gives sum `k`
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                ans += prefixSumCount[sum - k];
            }

            // Update the count of the current prefix sum in the map
            prefixSumCount[sum]++;
        }

        return ans;
    }
};
