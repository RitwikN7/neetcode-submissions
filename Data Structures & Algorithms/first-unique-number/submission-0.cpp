class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (const auto& num : nums)
            this->add(num);
    }
    
    int showFirstUnique() {
        if (queue_.empty())
            return -1;

        return queue_.front();
    }
    
    void add(int value) {
        if (isUnique_.find(value) == isUnique_.end())
        {
            isUnique_[value] = true;
            queue_.push_back(value);
            queuePosition_.insert({value, std::prev(queue_.end())});
        }
        else if (isUnique_[value])
        {
            isUnique_[value] = false;
            queue_.erase(queuePosition_[value]);
            queuePosition_.erase(value);
        }
    }

private:
    std::list<int> queue_;
    std::unordered_map<int, std::list<int>::iterator> queuePosition_;
    std::unordered_map<int, bool> isUnique_;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
