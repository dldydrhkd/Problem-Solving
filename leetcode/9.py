class Solution:
    def isPalindrome(self, x: int) -> bool:
        x = list(str(x))
        y = x[::-1]
        x = ''.join(x)
        y = ''.join(y)
        if(x==y):
            return True
        return False