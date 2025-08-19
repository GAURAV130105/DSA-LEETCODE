import sys
nums = list(map(int, sys.argv[1].split(',')))

class Solution:
    def removeDuplicates(self, nums):
        if not nums:  
            return 0

        i = 0  
        for j in range(1, len(nums)):
            if nums[j] != nums[i]:
                i += 1
                nums[i] = nums[j]

        return i + 1  

if __name__ == "__main__":
    nums = list(map(int, sys.argv[1].split(',')))
    sol = Solution()
    result = sol.removeDuplicates(nums)
    if result:
        print("Array after removing duplicates:", nums[:result])
    else:
        print("No solution found.")