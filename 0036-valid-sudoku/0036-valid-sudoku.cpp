class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; i++) {
            unordered_set<char> mpp;
            for (int j = 0; j < col; j++) {
                if (board[i][j] != '.') {
                    if (mpp.find(board[i][j]) == mpp.end()) {
                        mpp.insert(board[i][j]);
                    } else {
                        return false;
                    }
                }
            }
        }
        for (int j = 0; j < col; j++) {
            unordered_set<char> mpp;
            for (int i = 0; i < row; i++) {
                if (board[i][j] != '.') {
                    if (mpp.find(board[i][j]) == mpp.end()) {
                        mpp.insert(board[i][j]);
                    } else {
                        return false;
                    }
                }
            }
        }
        for (int i = 0; i < row; i += 3) {
            for (int j = 0; j < col; j += 3) {
                unordered_set<char> mpp;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        char val = board[i + x][j + y];

                        if (val != '.') {
                            if (mpp.find(val) == mpp.end()) {
                                mpp.insert(val);
                            } else {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};