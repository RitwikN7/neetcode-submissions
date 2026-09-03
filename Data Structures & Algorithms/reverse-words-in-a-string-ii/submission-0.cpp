class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());

        int start = 0;
        int n = s.size();

        for (int end = 0; end <= n; end++)
        {
            if (end == n || s[end] == ' ')
            {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
    }
};
