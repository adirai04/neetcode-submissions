class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stac;
        int n = tokens.size();

        for (int i = 0; i < n; i++) {
            string str = tokens[i];
            int val = check(str);

            if (val == -1) {
                int num = stoi(str);
                stac.push(num);
            } else {
                int y = stac.top();
                stac.pop();
                int x = stac.top();
                stac.pop();

                int res;

                if (val == 1) {
                    res = x + y;
                } 
                if (val == 2) {
                    res = x - y;
                } 
                if (val == 3) {
                    res = x * y;
                } 
                if (val == 4) {
                    res = x / y;
                } 

                stac.push(res);
            }
        }

        return stac.top();

    }

    int check(string str) {
        if (str == "+") {
            return 1;
        } else if (str == "-") {
            return 2;
        } else if (str == "*") {
            return 3;
        } else if (str == "/") {
            return 4;
        } else {
            return -1;
        }
    }
};