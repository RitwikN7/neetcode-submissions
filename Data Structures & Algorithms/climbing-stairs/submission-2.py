class Solution:
    def climbStairs(self, n: int) -> int:
        leftMost = 1
        left = 1
        for i in range(1, n):
            temp = left
            left = left + leftMost
            leftMost = temp

        return left