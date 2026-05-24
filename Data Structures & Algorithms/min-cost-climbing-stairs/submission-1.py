class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        if len(cost) == 0:
            return 0

        if len(cost) <= 2:
            return min(cost)
        
        leftMost = cost[0]
        left = cost[1]

        for i in range(2, len(cost)):
            temp = left
            left = cost[i] + min(temp, leftMost)
            leftMost = temp

        return min(left, leftMost)