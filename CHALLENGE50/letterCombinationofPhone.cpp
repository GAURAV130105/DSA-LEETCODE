class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res=[]
        DigitsToChar={
            "2":"abc",
            "3":"def",
            "4":"ghi",
            "5":"jkl",
            "6":"mno",
            "7":"qprs",
            "8":"tuv",
            "9":"wxyz"        }
        def backtrack(i,cs):
            if len(cs)==len(digits):
                res.append(cs)
                return
            for c in DigitsToChar[digits[i]]:
                backtrack(i+1,cs+c)
        if digits:
            backtrack(0,"")

        return res
    