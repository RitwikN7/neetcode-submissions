class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        def dfs(i, arr, target):
            if target == 0:
                res.append(arr.copy())
                return

            if i >= len(nums) or target < 0:
                return

            arr.append(nums[i])
            dfs(i, arr, target - nums[i])
            arr.pop()
            dfs(i + 1, arr, target)

        dfs(0, [], target)
        return res