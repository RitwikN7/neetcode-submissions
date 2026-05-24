class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int w = 0;
        int a = 0;

        while (w < word.size() && a < abbr.size())
        {
            if (word[w] == abbr[a])
            {
                w++;
                a++;
            }
            else
            {
                if (!isdigit(abbr[a]))
                    return false;

                if (abbr[a] == '0')
                    return false;
                
                int dStart = a;
                while (a < abbr.size())
                {
                    a++;
                    if (!isdigit(abbr[a]))
                        break;
                }
                int count = stoi(abbr.substr(dStart, a - dStart));
                w += count;
            }
        }
        return w == word.size() && a == abbr.size();
    }
};