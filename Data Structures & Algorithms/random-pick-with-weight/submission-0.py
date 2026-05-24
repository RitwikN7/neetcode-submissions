class Solution:

    def __init__(self, w: List[int]):
        self.index_list = []
        for i in range(len(w)):
            for j in range(w[i]):
                self.index_list.append([w[i], i])

        self.length = len(self.index_list)

    def pickIndex(self) -> int:
        randInt = random.randint(0, self.length - 1)
        return self.index_list[randInt][1]


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()