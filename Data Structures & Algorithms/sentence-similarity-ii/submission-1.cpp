class DSU
{
public:
    explicit DSU()
    {
        parent_.clear();
        rank_.clear();
    }

    void addWord(const std::string& w)
    {
        parent_.insert({w, w});
        rank_.insert({w, 0});
    }

    bool isWordPresent(const std::string& w)
    {
        return parent_.find(w) != parent_.end();
    }

    std::string find_parent(const std::string& w)
    {
        if (parent_[w] == w)
            return w;

        return parent_[w] = find_parent(parent_[w]);
    }

    void union_words(const std::string& u, const std::string& v)
    {
        auto a = find_parent(u);
        auto b = find_parent(v);

        if (a == b)
            return;

        if (rank_[a] < rank_[b])
            parent_[a] = b;
        else if (rank_[a] > rank_[b])
            parent_[b] = a;
        else
        {
            parent_[b] = a;
            rank_[a]++;
        }
    }
private:
    std::unordered_map<std::string, std::string> parent_;
    std::unordered_map<std::string, int> rank_;
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size())
            return false;

        int n = sentence1.size();
        DSU dsu;
        for (const auto& p : similarPairs)
        {
            dsu.addWord(p[0]);
            dsu.addWord(p[1]);
            dsu.union_words(p[0], p[1]);
        }

        for (int i{}; i < n; ++i)
        {
            const auto& w1 = sentence1[i];
            const auto& w2 = sentence2[i];
            if (w1 == w2)
                continue;

            if (!dsu.isWordPresent(w1) || !dsu.isWordPresent(w2))
                return false;

            if (dsu.find_parent(w1) != dsu.find_parent(w2))
                return false;
        }

        return true;
    }
};
