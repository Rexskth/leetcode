class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

      if(s.length()<10) return {};


        unordered_map<string, int> substringCount;
        vector<string> result;

        for (int i = 0; i <= s.length() - 10; i++) {
            string substring = s.substr(i, 10); // Extract 10-letter substring
            substringCount[substring]++;
        }

        for (const auto& pair : substringCount) {
            if (pair.second > 1) { // Occurrence greater than once
                result.push_back(pair.first);
            }
        }

        return result;
    }
};