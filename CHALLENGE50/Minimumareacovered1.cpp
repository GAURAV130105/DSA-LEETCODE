#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        int minRow = m, maxRow = -1;
        int minCol = n, maxCol = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        if (maxRow == -1 || maxCol == -1) return 0; // No 1s found
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};

int main() {
    int t;
    cout << "Enter number of testcases: ";
    cin >> t;

    while (t--) {
        int m, n;
        cout << "\nEnter number of rows and columns: ";
        cin >> m >> n;

        vector<vector<int> > grid(m, vector<int>(n));
        cout << "Enter grid values (0 or 1):\n";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        Solution sol;
        cout << "Minimum area covered: " << sol.minimumArea(grid) << endl;
    }

    return 0;
}
