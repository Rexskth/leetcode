// 100% Beats
class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> result;
        
        result.push_back(1);
        
        for (int i = 1; i <= rowIndex; i++) {
            long long currentElement = static_cast<long long>(result[i - 1]) * (rowIndex - i + 1) / i;
            result.push_back(static_cast<int>(currentElement));
        }
        
        return result;
    }
};