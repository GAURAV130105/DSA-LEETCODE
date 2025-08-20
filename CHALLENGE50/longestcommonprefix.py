
import sys
class Solution :
    def longestCommonPrefix(self,strs):
        if not strs:
            return ""
        prefix = strs[0]
        for string in strs[1:]:
            while string.find(prefix)!=0:
                prefix = prefix [:-1]
            if not prefix:
                return ""
        return prefix
    
if __name__ == "__main__":
    strs = list(map(str, sys.argv[1].split(',')))
    sol = Solution()
    result = sol.longestCommonPrefix(strs)
    if result:
        print("Longest common prefix:", result)
    else:
        print("No common prefix found.")
