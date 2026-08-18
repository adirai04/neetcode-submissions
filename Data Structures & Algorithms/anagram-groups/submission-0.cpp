class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for (string str : strs) {
            string ss = str;
            sort(ss.begin(), ss.end());

            mpp[ss].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
