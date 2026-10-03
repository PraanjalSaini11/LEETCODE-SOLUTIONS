class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        // All characters matched
        if (k == word.size())
            return true;

        // Out of bounds or wrong character
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size() ||
            board[i][j] != word[k])
            return false;

        // Mark as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore 4 directions
        bool found = dfs(board, word, i + 1, j, k + 1) ||
                     dfs(board, word, i - 1, j, k + 1) ||
                     dfs(board, word, i, j + 1, k + 1) ||
                     dfs(board, word, i, j - 1, k + 1);

        // Backtrack
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};