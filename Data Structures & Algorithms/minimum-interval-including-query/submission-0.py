class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        mp = defaultdict(lambda: -1)
        for elem in intervals:
            size = elem[1] - elem[0] + 1
            for i in range(elem[0], elem[1] + 1):
                if mp[i] == -1:
                    mp[i] = size
                else:
                    mp[i] = min(size, mp[i])

        res = [mp[i] for i in queries]
        return res 