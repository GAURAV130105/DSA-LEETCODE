import java.util.Scanner;

public class DiagonalTraverse {
    public int[] findDiagonalOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0) return new int[0];

        int m = matrix.length, n = matrix[0].length;
        int[] result = new int[m * n];
        int row = 0, col = 0;

        for (int i = 0; i < m * n; i++) {
            result[i] = matrix[row][col];

            if ((row + col) % 2 == 0) {
                // Moving up-right
                if (col == n - 1) row++;
                else if (row == 0) col++;
                else { row--; col++; }
            } else {
                // Moving down-left
                if (row == m - 1) col++;
                else if (col == 0) row++;
                else { row++; col--; }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take rows and columns from user
        System.out.print("Enter number of rows: ");
        int m = sc.nextInt();

        System.out.print("Enter number of columns: ");
        int n = sc.nextInt();

        int[][] matrix = new int[m][n];
        
        System.out.println("Enter matrix elements row by row:");

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        // Call function
        DiagonalTraverse sol = new DiagonalTraverse();
        int[] result = sol.findDiagonalOrder(matrix);

        // Print result
        System.out.println("Diagonal Order Traversal:");
        for (int num : result) {
            System.out.print(num + " ");
        }
    }
}
 