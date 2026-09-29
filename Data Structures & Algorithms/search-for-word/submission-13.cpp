class Solution {
    vector<pair<int, int>> visited;

   public:
    bool backtrack(int i, int j, vector<vector<char>>& board, string word, int idx) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;

        if (find(visited.begin(), visited.end(), make_pair(i, j)) != visited.end()) {
            return false;
        }

        if (idx == word.size() - 1 && word[idx] == board[i][j]) return true;
        
        if (board[i][j] == word[idx]) {
            visited.push_back({i, j});
            bool res = backtrack(i, j - 1, board, word, idx + 1) ||
                       backtrack(i, j + 1, board, word, idx + 1) ||
                       backtrack(i - 1, j, board, word, idx + 1) ||
                       backtrack(i + 1, j, board, word, idx + 1);
            visited.pop_back();
            return res;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        bool res = false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res = backtrack(i, j, board, word, 0);
                if (res) return res;
            }
        }
        return res;
    }
};
