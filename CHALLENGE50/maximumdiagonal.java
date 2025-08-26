import java.util.Scanner;

public class maximumdiagonal {
    public int areaofmaximumdiagonal(int[][] dimensions) {
        int n = dimensions.length;
        int maxdiagonal = 0, maxarea = 0;
        for (int i = 0; i < n; i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            int currdiagonal = l * l + w * w;
            if (currdiagonal > maxdiagonal || (currdiagonal == maxdiagonal && maxarea < l * w)) {
                maxdiagonal = currdiagonal;
                maxarea = l * w;
            }
        }
        return maxarea;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take number of rectangles from user
        System.out.print("Enter number of rectangles: ");
        int n = sc.nextInt();

        int[][] dimensions = new int[n][2];
        System.out.println("Enter length and width for each rectangle:");
        for (int i = 0; i < n; i++) {
            dimensions[i][0] = sc.nextInt(); // length
            dimensions[i][1] = sc.nextInt(); // width
        }

        maximumdiagonal sol = new maximumdiagonal();
        int result = sol.areaofmaximumdiagonal(dimensions);

        System.out.println("Maximum area of diagonal rectangle: " + result);
    }
}
