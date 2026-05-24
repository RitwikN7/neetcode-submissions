class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 1)
            return 1;
        char prev = chars[0];
        int count = 1;
        int p = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i == n || chars[i] != prev)
            {
                chars[p] = prev;
                p++;
                if (count > 1)
                {
                    string c = to_string(count);
                    for (char d : c)
                    {
                        chars[p] = d;
                        p++;
                    }
                }
                if (i < n)
                {
                    count = 1;
                    prev = chars[i];
                }
            }
            else
                count++;
        }
        return p;
    }
};