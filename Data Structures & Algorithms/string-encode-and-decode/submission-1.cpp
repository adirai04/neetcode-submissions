class Solution {
    vector<string> v;
public:
    string encode(vector<string>& strs) {
        string str = "";
        for (string s : strs) {
            v.push_back(s);
            str = str + s;
        }

        return str;
    }

    vector<string> decode(string s) {
        return v;
    }
};
