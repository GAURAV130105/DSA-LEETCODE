import java.util.Scanner;

class sudukovalidornot {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] rows = new boolean[9][9];
        boolean[][] cols = new boolean[9][9];
        boolean[][] boxes = new boolean[9][9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int boxIndex = (i / 3) * 3 + (j / 3);

                    if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) {
                        return false;
                    }

                    rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[][] board = new char[9][9];

        System.out.println("Enter Sudoku board (use '.' for empty cells):");
        for (int i = 0; i < 9; i++) {
            String row = sc.next(); // read row as string (9 characters)
            for (int j = 0; j < 9; j++) {
                board[i][j] = row.charAt(j);
            }
        }

        sudukovalidornot sol = new sudukovalidornot();
        if (sol.isValidSudoku(board)) {
            System.out.println("The Sudoku board is VALID ");
        } else {
            System.out.println("The Sudoku board is INVALID ");
        }
    }
}
