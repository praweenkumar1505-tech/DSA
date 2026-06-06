bool dfs(char** board, int rows, int cols, int r, int c, char* word, int index) {
    if (word[index] == '\0')
        return true;

    if (r < 0 || r >= rows || c < 0 || c >= cols ||
        board[r][c] != word[index])
        return false;

    char temp = board[r][c];
    board[r][c] = '#';  // mark visited

    bool found =
        dfs(board, rows, cols, r + 1, c, word, index + 1) ||
        dfs(board, rows, cols, r - 1, c, word, index + 1) ||
        dfs(board, rows, cols, r, c + 1, word, index + 1) ||
        dfs(board, rows, cols, r, c - 1, word, index + 1);

    board[r][c] = temp; // backtrack

    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int rows = boardSize;
    int cols = boardColSize[0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (dfs(board, rows, cols, i, j, word, 0))
                return true;
        }
    }

    return false;
}