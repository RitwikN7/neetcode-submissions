class CountSquares:

    def __init__(self):
        self.hashmap = {} # (x, y) : count

    def add(self, point: List[int]) -> None:
        x, y = point[0], point[1]
        if (x, y) in self.hashmap:
            self.hashmap[(x, y)] = self.hashmap[(x, y)] + 1
            return

        self.hashmap[(x, y)] = 1
        
    def count(self, point: List[int]) -> int:
        x, y = point[0], point[1]
        res = 0
        for point, count in self.hashmap.items():
            px, py = point[0], point[-1]
            if px == x or py == y:
                continue

            if abs(px - x) != abs(py - y):
                continue
            # found valid diagonal point
            if (x, py) in self.hashmap and (px, y) in self.hashmap:
                res += count * self.hashmap[(x, py)] * self.hashmap[(px, y)]

        return res

