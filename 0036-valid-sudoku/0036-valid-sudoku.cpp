class Solution {
public:

    bool isSafe(vector<vector<char>>& board,
                char digit,
                int row,
                int col) {

        // Check row
        for(int j = 0; j < 9; j++) {

            if(j != col && board[row][j] == digit)
                return false;
        }

        // Check column
        for(int i = 0; i < 9; i++) {

            if(i != row && board[i][col] == digit)
                return false;
        }

        // Check 3 x 3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for(int i = startRow; i < startRow + 3; i++) {

            for(int j = startCol; j < startCol + 3; j++) {

                if((i != row || j != col) &&
                   board[i][j] == digit) {

                    return false;
                }
            }
        }

        return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {

            for(int j = 0; j < 9; j++) {

                // Ignore empty cells
                if(board[i][j] == '.')
                    continue;

                char digit = board[i][j];

                if(!isSafe(board, digit, i, j))
                    return false;
            }
        }

        return true;
    }
};