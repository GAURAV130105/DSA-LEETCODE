#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int n = nums.size();
        int zeros = 0, ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            zeros += (nums[r] == 0);
            zeros -= (zeros > 1 && nums[l++] == 0);
            ans = max(ans, r - l);
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements (0 or 1): ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    Solution sol;
    cout << "Longest subarray after deleting one element: " << sol.longestSubarray(nums) << endl;
    return 0;
}
