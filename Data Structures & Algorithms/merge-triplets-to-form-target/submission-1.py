class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        def merge(i, j):
            return [max(triplets[i][0], triplets[j][0]), max(triplets[i][1], triplets[j][1]), max(triplets[i][2], triplets[j][2])]

        l = 0
        res = triplets[0]
        for r in range(1, len(triplets)):
            if res == target:
                return True

            if triplets[r][0] > target[0] or triplets[r][1] > target[1] or triplets[r][2] > target[2]:
                continue
                
            merged = merge(l, r)
            if merged[0] > target[0] or merged[1] > target[1] or merged[2] > target[2]:
                l = r
                res = triplets[r]
            else:
                res = merged
                triplets[l] = merged

        return res == target
            