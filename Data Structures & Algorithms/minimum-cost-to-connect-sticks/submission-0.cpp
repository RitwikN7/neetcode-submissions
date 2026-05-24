class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<>> minHeap;
        for (const auto& s : sticks)
            minHeap.push(s);

        int cost = 0;
        while (minHeap.size() > 1)
        {
            int s1 = minHeap.top();
            minHeap.pop();
            int s2 = minHeap.top();
            minHeap.pop();
            cost += s1 + s2;
            minHeap.push(s1 + s2);
        }
        return cost;
    }
};
