class Solution {
    int m, n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (solve(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool solve(vector<vector<char>>& board, string &word, int i, int j, int idx) {
        if (idx >= word.size()) {
            return true;
        }

        if (i < 0 || j < 0 || i >= m || j >= n) {
            return false;
        }

        if (board[i][j] == '#') {
            return false;
        }

        if (board[i][j] != word[idx]) {
            return false;
        }

        char ch = board[i][j];
        board[i][j] = '#';

        bool a = solve(board, word, i + 1, j, idx + 1);
        bool b = solve(board, word, i - 1, j, idx + 1);
        bool c = solve(board, word, i, j + 1, idx + 1);
        bool d = solve(board, word, i, j - 1, idx + 1);

        board[i][j] = ch;

        return a || b || c || d;
    }
};
