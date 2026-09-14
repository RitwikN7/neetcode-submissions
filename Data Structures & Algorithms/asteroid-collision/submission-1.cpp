class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::vector<int> res;
        for (int i{}; i < asteroids.size(); ++i)
        {
            int a = asteroids[i];
            while (a < 0 && !res.empty() && res.back() > 0)
            {
                int diff = res.back() - std::abs(a);
                if (diff == 0)
                {
                    a = 0;
                    res.pop_back();
                }
                else if (diff < 0)
                {
                    res.pop_back();
                }
                else
                {
                    a = 0;
                }
            }

            if (a != 0)
                res.push_back(a);
        }

        return res;
    }
};