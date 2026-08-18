class Solution {
public:
    bool isValid(string s) {
        stack<char> stac;
        for (char par : s) {
            if (par == '(' || par == '{' || par == '[') {
                stac.push(par);
            } else {
                if (stac.empty()) return false;

                char open = stac.top();
                if (check(open, par)) stac.pop();
                else return false;
            }
        }

        return stac.empty();
    }

    bool check(char open, char close) {
        if (open == '(' && close == ')') return true;
        if (open == '{' && close == '}') return true;
        if (open == '[' && close == ']') return true;

        return false;
    }
};
