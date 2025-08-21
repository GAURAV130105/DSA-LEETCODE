class Solution:
    def isPalindrome(self, x):
        if x < 0:
            return False
        original = x
        reverse = 0
        while x != 0:
            reverse = reverse * 10 + x % 10
            x = x // 10
        return reverse == original

if __name__ == "__main__":
    print("Enter a number to check if it is a palindrome:")
    x = int(input())
    sol = Solution()
    if sol.isPalindrome(x):
        print(x, "is a palindrome.")
    else:
        print(x, "is not a palindrome.")