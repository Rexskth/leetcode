class Solution {
public:
    void backtrack(string& digits, vector<string>& result, string& current, int index, unordered_map<char, string>& mapping) {
        if (index == digits.size()) { // Base case: if we've processed all digits
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index]];
        for (char letter : letters) {
            current.push_back(letter);       // Choose a letter
            backtrack(digits, result, current, index + 1, mapping); // Explore further
            current.pop_back();             // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; 

        unordered_map<char, string> mapping = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> result;
        string current;
        backtrack(digits, result, current, 0, mapping);
        return result;
    }
};