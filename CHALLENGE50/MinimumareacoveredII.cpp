#include <vector>
#include <unordered_map>
#include <string>
#include <climits>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
    unordered_map<string, int> memo;
public:
    int minimumSum(vector<vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();

        function<int(int, int, int, int, int)> getOne = [&](int i1, int j1, int i2, int j2, int k) {
            int minx = INT_MAX;
            int maxx = INT_MIN;
            int miny = INT_MAX;
            int maxy = INT_MIN;

            for (int i = i1; i <= i2; ++i) {
                for (int j = j1; j <= j2; ++j) {
                    if (grid[i][j] == 1) {
                        minx = min(minx, i);
                        maxx = max(maxx, i);
                        miny = min(miny, j);
                        maxy = max(maxy, j);
                    }
                }
            }

            if (minx == INT_MAX) {
                return 0;
            }

            return (maxx - minx + 1) * (maxy - miny + 1);
        };

        function<int(int, int, int, int, int)> getNext = [&](int i1, int j1, int i2, int j2, int k) {
            string key = to_string(i1) + "," + to_string(j1) + "," + to_string(i2) + "," + to_string(j2) + "," + to_string(k);
            if (memo.find(key) != memo.end()) {
                return memo[key];
            }

            int output = INT_MAX;

            if (k == 1) {
                output = getOne(i1, j1, i2, j2, k);
            } else if (k == 2) {
                for (int i = i1; i < i2; ++i) {
                    output = min(output, getNext(i1, j1, i, j2, 1) + getNext(i + 1, j1, i2, j2, 1));
                }
                for (int j = j1; j < j2; ++j) {
                    output = min(output, getNext(i1, j1, i2, j, 1) + getNext(i1, j + 1, i2, j2, 1));
                }
            } else if (k == 3) {
                for (int i = i1; i < i2; ++i) {
                    output = min(output, getNext(i1, j1, i, j2, 1) + getNext(i + 1, j1, i2, j2, 2));
                    output = min(output, getNext(i1, j1, i, j2, 2) + getNext(i + 1, j1, i2, j2, 1));
                }
                for (int j = j1; j < j2; ++j) {
                    output = min(output, getNext(i1, j1, i2, j, 1) + getNext(i1, j + 1, i2, j2, 2));
                    output = min(output, getNext(i1, j1, i2, j, 2) + getNext(i1, j + 1, i2, j2, 1));
                }
            }

            memo[key] = output;
            return output;
        };

        int ans = getNext(0, 0, m - 1, n - 1, 3);
        return ans;
    }
};