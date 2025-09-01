import sys
nums = list(map(int, sys.argv[1].split(',')))
target = int(sys.argv[2])

class Solution :

    
    def TwoSum(self, nums , target ):
       
        number_map={}
        for i, num in enumerate(nums):
            diff = target - num
            if diff in number_map:
                return [number_map[diff], i]
            number_map[num] = i
        return None

if __name__ == "__main__":
    nums = list(map(int, sys.argv[1].split(',')))
    target = int(sys.argv[2])
    sol = Solution()
    result = sol.TwoSum(nums, target)
    if result:
        print("Indices:", result)
    else:
        print("No solution found.")