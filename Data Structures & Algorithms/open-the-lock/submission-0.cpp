class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;

        unordered_set<string> visit(deadends.begin(), deadends.end());
        if (visit.count("0000")) return -1;

        unordered_set<string> begin = {"0000"}, end = {target};
        int steps = 0;

        while (!begin.empty() && !end.empty())
        {
            if (begin.size() > end.size())
                std::swap(begin, end);

            steps++;
            unordered_set<string> temp;
            for (const string& lock : begin)
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int j : {1, -1})
                    {
                        string nextLock = lock;
                        nextLock[i] = (nextLock[i] - '0' + j + 10) % 10 + '0';
                        if (end.contains(nextLock))
                            return steps;

                        if (visit.contains(nextLock))
                            continue;

                        visit.insert(nextLock);
                        temp.insert(nextLock);
                    }
                }
            }

            begin = temp;
        }

        return -1;
    }
};