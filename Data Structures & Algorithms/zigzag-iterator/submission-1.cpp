class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2)
    {
        vectors_.push_back(v1);
        vectors_.push_back(v2);

        if (!v1.empty())
            queue_.push({0, 0});

        if (!v2.empty())
            queue_.push({1, 0});
    }

    int next() {
        if (!hasNext())
            return 0;

        auto [vec, idx] = queue_.front();
        queue_.pop();
        if (idx < vectors_[vec].size() - 1)
            queue_.push({vec, idx + 1});

        return vectors_[vec][idx];
    }

    bool hasNext() {
        return !queue_.empty();
    }
private:
    vector<vector<int>> vectors_;
    std::queue<std::pair<int, int>> queue_; // vector, index
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
