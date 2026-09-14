class MaxStack {
public:
    MaxStack() = default;
    
    void push(int x) {
        stk_.push({x, cnt_});
        max_heap_.push({x, cnt_});
        ++cnt_;
    }
    
    int pop() {
        while (removed_.contains(stk_.top().second))
            stk_.pop();

        const auto [x, count] = stk_.top();
        stk_.pop();
        removed_.insert(count);
        return x;
    }
    
    int top() {
        while (removed_.contains(stk_.top().second))
            stk_.pop();

        return stk_.top().first;
    }
    
    int peekMax() {
        while (removed_.contains(max_heap_.top().second))
            max_heap_.pop();

        return max_heap_.top().first;
    }
    
    int popMax() {
        while (removed_.contains(max_heap_.top().second))
            max_heap_.pop();

        const auto [x, count] = max_heap_.top();
        max_heap_.pop();
        removed_.insert(count);
        return x;
    }

private:
    stack<pair<int, int>> stk_;
    priority_queue<pair<int, int>> max_heap_;
    unordered_set<int> removed_;
    int cnt_{};
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
