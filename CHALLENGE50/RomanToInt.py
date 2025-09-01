class Solution:
    def romanToInt(self, s):
        romantointdict = {
            'I': 1, 'V': 5, 'X': 10, 
            'L': 50, 'C': 100, 'D': 500, 'M': 1000
        }
        result = 0 
        for i in range(len(s) - 1, -1, -1):
            currValue = romantointdict[s[i]]   

            if i < len(s) - 1 and currValue < romantointdict[s[i+1]]:
                result -= currValue
            else:
                result += currValue 
        return result 

if __name__ == "__main__":
    print("Enter the valid Roman numeral:")
    s = str(input())
    sol = Solution()
    print("The integer value is:", sol.romanToInt(s))